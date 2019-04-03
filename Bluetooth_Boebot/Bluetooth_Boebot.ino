/******************************************************************************
Version 1.0
Date: April 2nd, 2019
Author: Yondertag

This is rewritten code is based off of the 'BluebotSonar' code from 42bots.
This code is modeled for the arduino Boebot with continious servos and 
HC-05 bluetooth module. The code that is designed to control the bluetooth Boebot
can be downloaded as .apk from Github here: 
The code can be downloaded as .aia from Github here: 


********************************************************************************/

#include <Servo.h>
#include <SoftwareSerial.h>

Servo servoLeft;
Servo servoRight;

int input = 0;            // input from the control device
int flag = 0;             // makes sure that the serial only prints once the input
const int ledPin = 8;     // an LED used to indicate visually when a known 
						   // command is received
SoftwareSerial mySerial(12, 9); // Initialize SoftwareSerial (RX, TX)
 
void setup() 
{ 
  servoLeft.attach(13);                      // Attach left signal to P13 
  servoRight.attach(10);                     // Attach right signal to P12 
  
  // sets the LED pin as outputs:
  pinMode(ledPin, OUTPUT);
  mySerial.begin(9600);
} 
 
 
void loop() 
{ 
    //if some date is sent, reads it and saves it in the input variable
    if(mySerial.available() > 0){     
      input = mySerial.read();   
      flag=0;
    }
    
    // If it receives '5' on the serial port, stop both servos
    if (input == 5) {
      servoLeft.detach();                      // Attach left signal to P13 
      servoRight.detach();                     // Attach right signal to P12 
        if(flag == 0){
          flag = 1;
        }
    }
    // If you receive '1' on the serial port, check the distance to the closest obstacle ahead
    else if (input == 1) {
        //move forward if path ahead is clear
      servoLeft.attach(13);                      // Attach left signal to P13 
      servoRight.attach(10);                     // Attach right signal to P12 
      servoLeft.writeMicroseconds(1420);         // 1.3 ms 
      servoRight.writeMicroseconds(1620);        // 1.7 ms 
        if(flag == 0){
          flag = 1;
        }

    }
    // If you receive '3' on the serial port, rotate right
    else if (input == 3) {
      servoLeft.attach(13);                      // Attach left signal to P13 
      servoRight.attach(10);                     // Attach right signal to P12 
      servoLeft.writeMicroseconds(1650);         
      servoRight.writeMicroseconds(1650);    
        if(flag == 0){
          flag = 1;
        }
        digitalWrite(ledPin, LOW); 
    }
    // If you receive '4' on the serial port, rotate left
    else if (input == 4) {
      servoLeft.attach(13);                      // Attach left signal to P13 
      servoRight.attach(10);                     // Attach right signal to P12 
      servoLeft.writeMicroseconds(1350);
      servoRight.writeMicroseconds(1350);
        if(flag == 0){
          flag = 1;
        }
        digitalWrite(ledPin, LOW); 
    }
    // If you receive '2' on the serial port, check the distance to the closest obstacle behind
    else if (input == 2) {
      //reverse
      servoLeft.attach(13);                      // Attach left signal to P13 
      servoRight.attach(10);                     // Attach right signal to P12 
      servoLeft.writeMicroseconds(1600);
      servoRight.writeMicroseconds(1400);
      
        if(flag == 0){
          flag = 1;
        }
        digitalWrite(ledPin, LOW); 
      }
         else if (input == 6) {
           //stop if released
           servoLeft.detach();                      // Attach left signal to P13 
           servoRight.detach();                     // Attach right signal to P12 
        if(flag == 0){
          flag = 1;
        }
        digitalWrite(ledPin, LOW); 
      }
    
    else {
      digitalWrite(ledPin, LOW);
    }
}
