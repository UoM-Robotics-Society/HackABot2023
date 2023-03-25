#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // Create an instance of the NRF24L01+ module with CE and CSN pins connected to pins 7 and 8, respectively.

const byte address[6] = "00001"; // Define the address of the receiving NRF24L01+ module.

void setup() {
  Serial.begin(9600);
  if (!radio.begin()){
    Serial.println(F("Hardware not responding."));
  }
  radio.openWritingPipe(address); // Open a writing pipe to the receiving NRF24L01+ module using the defined address.
}

void loop() {
  String message = "Hello, world!"; // Define the message to be sent.
  
  radio.write(&message, sizeof(message)); // Send the message through the NRF24L01+ module.
  
  //Serial.println("Message sent: " + message); // Print a message to the serial monitor indicating that the message has been sent.
  
  delay(1000); // Wait for 1 second before sending the next message.
}
