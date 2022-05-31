// HOUSE PET INFRARED REMOTE-CONTROLLED FEEDER USING ARDUINO UNO

#include <Servo.h>
#include <IRremote.hpp>

IRrecv receiver(8);
Servo servoMotor;

void setup()
{
  Serial.begin(9600);
  receiver.enableIRIn();
  servoMotor.attach(3);
  servoMotor.write(0);
}

void loop()
{
  if(receiver.decode()){
    //if 1 button in remote is pressed [ON]
    if(receiver.decodedIRData.decodedRawData==4010852096){
    	servoMotor.write(180);
    }
    //if 0 button in remote is pressed [OFF]
    if(receiver.decodedIRData.decodedRawData==4077698816){
    	servoMotor.write(0);
    }
    receiver.resume();
  }
}

//0 button signal = 4010852096
//1 button signal = 4077698816