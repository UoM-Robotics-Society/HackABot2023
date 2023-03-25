// Basic test of Mona robot including proximity sensors and open-loop motion control

#include <RF24.h>
// instantiate an object for the nRF24L01 transceiver
RF24 radio(7, 8);  // using pin 7 for the CE pin, and pin 8 for the CSN pin
// Let these addresses be used for the pair
int payload = 0;
const byte address[6] = "00001"; // Define the address of the receiving NRF24L01+ module.
// pin config for basic platform test
// Motors
int Motor_right_PWM = 10;  //   0 (min speed) - 255 (max speed) 
int Motor_right_direction = 5;  //   0 Forward - 1 Reverse
int Motor_left_PWM = 9;    //   0 (min speed) - 255 (max speed)  
int Motor_left_direction = 6;   //   0 Forward - 1 Reverse
#define Forward 0
#define Reverse 1
// LED
int LED1 = 13;
int LED2 = 12;
int IR_enable=4;
int IR_threshold= 900; // 0 white close obstacle -- 1023 no obstacle


void setup() {
// initialize serial communication at 9600 bits per second:
 Serial.begin(115200);
// initialize Ports
  pinMode(Motor_left_PWM, OUTPUT);
  pinMode(Motor_right_PWM, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(IR_enable, OUTPUT);
  radio.begin();
  // Set the PA Level low to try preventing power supply related problems
  // because these examples are likely run with nodes in close proximity to
  // each other.
  //radio.setPALevel(RF24_PA_LOW);  // RF24_PA_MAX is default.

  // save on transmission time by setting the radio to only transmit the
  // number of bytes we need to transmit a float
  //radio.setPayloadSize(sizeof(payload));  // float datatype occupies 4 bytes

  // set the RX address of the TX node into a RX pipe
  radio.openReadingPipe(1, address);  // using pipe 1

  // additional setup specific to the node's role
  radio.startListening();  // put radio in RX mo
}

void forward(){
  analogWrite(Motor_right_PWM,120); // right motor
  digitalWrite(Motor_right_direction,Forward); //right
  analogWrite(Motor_left_PWM, 120); // left 
  digitalWrite(Motor_left_direction,Forward); //left
}

void reverse(int delay_time){
  analogWrite(Motor_right_PWM,120 ); // right motor
  digitalWrite(Motor_right_direction,Reverse); //right
  analogWrite(Motor_left_PWM, 120); // left 
  digitalWrite(Motor_left_direction,Reverse); //left
  delay(delay_time);
}

void right(int delay_time){
  reverse(50);
  analogWrite(Motor_right_PWM,120 ); // right motor
  digitalWrite(Motor_right_direction,Reverse); //right
  analogWrite(Motor_left_PWM, 40); // left 
  digitalWrite(Motor_left_direction,Forward); //left
  delay(delay_time);
}

void left(int delay_time){
  reverse(50);
  analogWrite(Motor_right_PWM,40 ); // right motor
  digitalWrite(Motor_right_direction,Forward); //right
  analogWrite(Motor_left_PWM, 120); // left 
  digitalWrite(Motor_left_direction,Reverse); //left
  delay(delay_time);
}

// Variables for 5 IR proximity sensors 
int IR_right,IR_right_front,IR_front,IR_left_front,IR_left;

void IR_proximity_read(){    // read IR sensors 
  int n=5;  // average parameter
  digitalWrite(IR_enable, HIGH);  //IR Enable
  IR_right=0;
  IR_right_front=0;
  IR_front=0;
  IR_left_front=0;
  IR_left=0;
  for (int i=0;i<n;i++){
    IR_right+=analogRead(A3);
    IR_right_front+=analogRead(A2);
    IR_front+=analogRead(A1);
    IR_left_front+=analogRead(A0);
    IR_left+=analogRead(A7);
    delay(5);
  }
  IR_right/=n;
  IR_right_front/=n;
  IR_front/=n;
  IR_left_front/=n;
  IR_left/=n; 
}

// obstacle avoidance
void Obstacle_avoidance(){
  if (IR_front<IR_threshold){
      digitalWrite(LED2,HIGH);
      reverse(300);
      right(500);
      digitalWrite(LED2,LOW);
  }
  if (IR_right<IR_threshold || IR_right_front<IR_threshold ){
      digitalWrite(LED2,HIGH);
      right(500);
      digitalWrite(LED2,LOW);
  } else {
      if (IR_left<IR_threshold || IR_left_front<IR_threshold ){
          digitalWrite(LED2,HIGH);
          left(500);
          digitalWrite(LED2,LOW);
      } else forward();
  }  
}

// send IR readings to Serial Monitor
void Send_sensor_readings(){
 Serial.print(IR_right);
 Serial.print(',');
 Serial.print(IR_right_front);
 Serial.print(',');
 Serial.print(IR_front);
 Serial.print(',');
 Serial.print(IR_left_front);
 Serial.print(',');
 Serial.println(IR_left);  
}


// the loop routine runs over and over again forever:
void loop() {
    uint8_t pipe;
    if (radio.available(&pipe)) {  
      digitalWrite(LED1,HIGH);
      digitalWrite(LED2,HIGH);
      //uint8_t bytes = radio.getPayloadSize();  // get the size of the payload
      long data;
      radio.read(&data, sizeof(long));
      String receivedString = String(data);
      //receivedString.trim(); // remove any leading/trailing white space
      Serial.println(receivedString);
      //Serial.println(receivedString);
      int values[5]; // array to store the split values
      values[0] = receivedString[0]- '0';
      values[1] = receivedString[1]- '0';
      values[2] = receivedString[2]- '0';
      values[3] = receivedString.substring(3,6).toInt();
      values[4] = receivedString.substring(6,9).toInt();
      Serial.print(values[0]);Serial.print(",");
      Serial.print(values[1]);Serial.print(",");
      Serial.print(values[2]);Serial.print(",");
      Serial.print(values[3]);Serial.print(",");
      Serial.print(values[4]);Serial.println(",");
      if (values[0]==7){
        Serial.print("I'm moving!");
        analogWrite(Motor_right_PWM,values[4] ); // right motor
        digitalWrite(Motor_right_direction,values[2]); //right
        analogWrite(Motor_left_PWM, values[3]); // left 
        digitalWrite(Motor_left_direction,values[1]); //left
      }
      /*
      Serial.print(bytes);  // print the size of the payload
      Serial.print(F(" bytes on pipe "));
      Serial.print(pipe);  // print the pipe number
      Serial.print(F(": "));
      Serial.println(payload);  // print the payload's value
      */
    }
 delay(100);        // delay in between reads for stability
 digitalWrite(LED1,LOW);
 digitalWrite(LED2,LOW);
}
