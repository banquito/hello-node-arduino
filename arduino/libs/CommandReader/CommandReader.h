#ifndef _CommandReader_h_
#define _CommandReader_h_

#include "Arduino.h"

class CommandReader {
public:
	CommandReader();
	void init(int baudRate);
	bool hasCommand();
	String getCommand();
	void serialEvent();
private: 
	String command;
	boolean isComplete;
};

#endif
