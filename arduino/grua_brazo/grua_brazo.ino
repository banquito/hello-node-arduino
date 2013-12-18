#include <MotorShield.h>
#include <Servo.h>
#include <CommandReader.h>

const int top = 110;
MS_DCMotor motorH(MOTOR_A);
MS_DCMotor motorV(MOTOR_B);
Servo servo1;
Servo servo2;
CommandReader commandReader;

void setup() {
  motorH.run(BRAKE);
  motorH.setSpeed(255);
  motorV.run(BRAKE);
  motorV.setSpeed(255);
  servo1.attach(6);
  servo1.write(0);  
  servo2.attach(5);
  servo2.write(0);  
  
  commandReader.init(9600);  
}

void loop() {
  String command;
  if (commandReader.hasCommand()) {
    command = commandReader.getCommand();
    Serial.println(command); 
    if (command == "grua.izq") {
      gruaIzq();
    } else if (command == "grua.der") {
      gruaDer();
    } else if (command == "grua.arriba") {
      gruaArriba();
    } else if (command == "grua.abajo") {
      gruaAbajo();
    } else if (command == "brazo.abrir") {
      brazoAbrir();
    } else if (command == "brazo.cerrar") {
      brazoCerrar();
    }    
  }
}

void gruaIzq() {
  motorH.run(BACKWARD|RELEASE);
  delay(1000);
  motorH.run(BRAKE);
}

void gruaDer() {
  motorH.run(FORWARD|RELEASE);
  delay(1000);
  motorH.run(BRAKE);
}

void gruaArriba() {
  motorV.run(FORWARD|RELEASE);
  delay(1000);
  motorV.run(BRAKE);
}

void gruaAbajo() {
  motorV.run(BACKWARD|RELEASE);
  delay(1000);
  motorV.run(BRAKE);
}

void brazoCerrar() {
  for(int pos = 0; pos <= top; pos += 1)
  {
    servo1.write(pos);
    servo2.write(pos);        
    delay(5);
  }
}

void brazoAbrir() {
  for(int pos = top; pos >= 0; pos -= 1)
  {
    servo1.write(pos);
    servo2.write(pos);        
    delay(5);
  }
}

void serialEvent() {
  commandReader.serialEvent();
}
