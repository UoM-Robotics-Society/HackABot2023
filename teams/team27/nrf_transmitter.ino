/*
  Arduino Wireless Network - Multiple NRF24L01 Tutorial
          == Base/ Master Node 00==
  by Dejan, www.HowToMechatronics.com
  Libraries:
  nRF24/RF24, https://github.com/nRF24/RF24
  nRF24/RF24Network, https://github.com/nRF24/RF24Network
*/

#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>

#define button 2
#define led 3

RF24 radio(7, 8);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 00;   // Address of this node in Octal format ( 04,031, etc)
const uint16_t node01 = 01;      // Address of the other node in Octal format
const uint16_t node02 = 02;      // Address of the other node in Octal format
char myCmd[10]="0000000000";
char a[9] = "000000000";
char g[9] = "000000000";
int i=0;
void setup() {
  Serial.begin(9600);
  SPI.begin();
  radio.begin();
  network.begin(90, this_node);  //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  
  if(Serial.available()>0)
   {
  //for(int i=0; i<5;i++){
  i=0;
  while(Serial.available()>0 && i<9){
   myCmd[i] = Serial.read();
  i++;
    }
   while(i<9){
    myCmd[i] = ' ';
    i++;
   }

   if(myCmd[0]=='a'){
    for(int i=0; i<9; i++){
      a[i] = myCmd[i+1];
    }
   }
   if(myCmd[0]=='g'){
    for(int i=0; i<9; i++){
      g[i] = myCmd[i+1];
    }
   }
   
   
   
  // if(myCmd[i]==')
  
  // if (myCmd=="\r")
   // return;
    
 
   
  network.update();
// see if there's incoming serial data:

  //===== Receiving =====//
  while ( network.available() ) {     // Is there any incoming data?
    RF24NetworkHeader header;
    unsigned long incomingData;
    network.read(header, &incomingData, sizeof(incomingData)); // Read the incoming data
    analogWrite(led, incomingData);    // PWM output to LED 01 (dimming)
  }
  //===== Sending =====//
  
  RF24NetworkHeader header1(node01);     // (Address where the data is going)
   //char text1[5]= "   ";
   //strncat(text1,&myCmd,1);
   
  //text1[0]= myCmd[0];
  bool ok1 = network.write(header1, &a, sizeof(a)); // Send the data
    // LED Control at Node 02
  RF24NetworkHeader header2(node02);    // (Address where the data is going)
  //const char text2[] = "Player 2";
  bool ok2 = network.write(header2, &g, sizeof(g)); // Send the data
   }
  delay(150);
  
}
