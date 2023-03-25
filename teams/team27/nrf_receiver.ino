/*
  Arduino Wireless Network - Multiple NRF24L01 Tutorial
        == Node 02 (Child of Master node 00) ==
*/

#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>

int Motor_right_PWM = 10;  //   0 (min speed) - 255 (max speed) 
int Motor_right_direction = 5;  //   0 Forward - 1 Reverse
int Motor_left_PWM = 9;    //   0 (min speed) - 255 (max speed)  
int Motor_left_direction = 6;   //   0 Forward - 1 Reverse

#define led 2

RF24 radio(7, 8);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 01;   // Address of our node in Octal format ( 04,031, etc)
const uint16_t master00 = 00;    // Address of the other node in Octal format

int LED1 = 13;
int LED2 = 12;
int IR_enable=4;
int IR_threshold= 900; // 0 white close obstacle -- 1023 no obstacle
int directiona = 1;
int directionb = 1;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  radio.begin();
  network.begin(90, this_node); //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
 
   pinMode(Motor_left_PWM, OUTPUT);
  pinMode(Motor_right_PWM, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(IR_enable, OUTPUT);
  Serial.println("started!");
   analogWrite(Motor_right_PWM, 255); // right motor
        digitalWrite(Motor_right_direction, directiona); //right
        analogWrite(Motor_left_PWM, 255); // left 
        digitalWrite(Motor_left_direction,directionb); //left
}

void loop() {
  network.update();
  //===== Receiving =====//
  while ( network.available() ) {     // Is there any incoming data?
    RF24NetworkHeader header;
    unsigned long incomingData;
    char text[9] = "000000000";
    network.read(header, &text, sizeof(text)); // Read the incoming data
    if (header.from_node == 0) {    // If data comes from Node 02
          Serial.print(text);
          Serial.println();
        String myString = String(text);
        String turn;
        String r;
        
        if (myString.indexOf(' ') == -1)
        {
        r = myString.substring(myString.indexOf(',')+1);
        }else 
        {
        r = myString.substring(myString.indexOf(',')+1,myString.indexOf(' '));
        }
        Serial.println(myString);
        
        
        int val = r.toInt();
        int val2;
        turn = myString.substring(0, myString.indexOf(','));
        Serial.println("turn " + turn);
        Serial.println("r "+r);
        int dir = turn.toInt();
        if (val < 0)
        {
          Serial.println("backwards"); 
          directiona = 0;
          directionb = 0;
          
          val2 = abs(val);
        }else
        {
          Serial.println("forwards");
          val2 = 255 - val;
          directiona = 1;
          directionb = 1;
        }
       
        Serial.println(val2); //wheel
        Serial.println(dir);
        
        int wheel1 = (val2) - (dir);
        int wheel2 = (val2) + (dir);
        Serial.println("w1");
        Serial.println(wheel1);
        Serial.println("w2");
        Serial.println(wheel2);

        if (wheel2 > 255 && directionb == 1)
        {
         wheel2 = wheel2-255;
         Serial.println("w2ff");
        directionb = 0; //invert
        }
         if (wheel1 > 255 && directiona == 1)
        {
          Serial.println("w1ff");
         wheel1 = wheel1 -255;
        directiona = 0; //invert
        }
        

        if (wheel1 <0 && directiona == 0)
        {
          wheel1 = 255 + wheel1;
          directiona = 1; //invert
        }
          if (wheel2 <0 && directionb == 0)
        {
          wheel2 = 255 + wheel2;
          directionb = 1; //invert
        }
        


     if (wheel2 > 255 && directionb == 0)
        {
         wheel2 = 255;
        
        }
         if (wheel1 > 255 && directiona == 0)
        {
       
         wheel1 = 255;
      
        }


      
        if (wheel1 <0 && directiona == 1)
        {
          wheel1 = 0;
          
        }
          if (wheel2 <0 && directionb == 1)
        {
          wheel2 = 0;
          
        }
        Serial.println("wf");
        Serial.println(wheel1);
        Serial.println("wf");
        Serial.println(wheel2);
        analogWrite(Motor_right_PWM,wheel1); // right motor
        digitalWrite(Motor_right_direction, directiona); //right
        analogWrite(Motor_left_PWM, wheel2); // left 
        digitalWrite(Motor_left_direction,directionb); //left
        
    }
 
  }
}
 