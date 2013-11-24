#include <SoftwareServo.h>

SoftwareServo servo;

void setup()
{
  pinMode(13,OUTPUT);
  servo.attach(A1);
  servo.setMaximumPulse(2200);
  servo.write(0);
  Serial.begin(9600);
  Serial.print("Ready");
}

void loop()
{
  static int value = 0;

  if ( Serial.available()) {
    char ch = Serial.read();
    if (ch == '0') {
      servo.write(0);
      Serial.print("0");
    } else if (ch == '5') {
      servo.write(90);  
      Serial.print("90");      
    } else if (ch == '9') {
      servo.write(180);  
      Serial.print("180");      
    }

      Serial.print(ch);
  }
  SoftwareServo::refresh();
}
