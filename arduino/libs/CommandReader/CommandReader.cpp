#include "Arduino.h"
#include "CommandReader.h" 

CommandReader::CommandReader()
{
  command.reserve(200);  
  command = "";
  isComplete = false;
}

void CommandReader::init(int baudRate) {
  Serial.begin(9600);
  Serial.println("hola");   
};

bool CommandReader::hasCommand() {
	return isComplete;
}

String CommandReader::getCommand() {
	String oldCommand = command;
  isComplete = false;
  command = "";
  return oldCommand;
}

void CommandReader::serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      isComplete = true;
    } else {
      // add it to the inputString:
      command += inChar;
    }
  }
}
