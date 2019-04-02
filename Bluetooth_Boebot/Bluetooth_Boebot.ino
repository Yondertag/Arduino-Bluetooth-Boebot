#include <Servo.h>

Servo panServo, tiltServo;

void setup() {

panServo.attach(9);

tiltServo.attach(6);

Serial.begin(38400); }

void loop() {

if(Serial.available()>= 2 ) {

unsigned int servopos = Serial.read();

unsigned int servopos1 = Serial.read();

unsigned int realservo = (servopos1 *256) + servopos;

Serial.println (realservo);

if (realservo >= 550 && realservo <750){

int servo1 = realservo;

servo1 = map(servo1,550,750,10,170);

panServo.write(servo1);

Serial.println(servo1);

delay(10);

}

if (realservo >= 250 && realservo <450){

int servo2 = realservo;

servo2 = map(servo2,250,450,170,10);

tiltServo.write(servo2);

Serial.println(servo2);

delay(10);

}

}

}
