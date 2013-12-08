#include <MotorShield.h>
#include <Servo.h>
#include <CommandReader.h>

const int ledPin = 13;

MS_DCMotor motor(MOTOR_A);
Servo servo;

CommandReader commandReader;

void setup() {
  pinMode(ledPin,OUTPUT);
  
  motor.run(BRAKE);
  motor.setSpeed(255);
  
  servo.attach(7);
  servo.write(0);  

  commandReader.init(9600);  
}

void loop() {
  String command;
  if (commandReader.hasCommand()) {
    command = commandReader.getCommand();
    Serial.println(command); 
    if (command == "arm.up") {
      armUp();
    } else if (command == "arm.down") {
      armDown();
    } else if (command == "load.up") {
      loadUp();
    } else if (command == "load.down") {
      loadDown();
    }
    
  }
}

void armDown() {
  int top = 180;
  for(int pos = 0; pos <= top; pos += 1)
  {
    servo.write(pos);
    delay(10);
  }
}

void armUp() {
  int top = 180;
  for(int pos = top; pos >= 0; pos -= 1)
  {
    servo.write(pos);
    delay(10);
  }
}

void loadUp() {
  motor.run(FORWARD|RELEASE);
  delay(3000);
  motor.run(BRAKE);
}

void loadDown() {
  motor.run(BACKWARD|RELEASE);
  delay(1000);
  motor.run(BRAKE);
}

void serialEvent() {
  commandReader.serialEvent();
}