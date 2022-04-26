#pragma once
#include "baseMessage.h"
#include "buffer.h"
class camera
{
private:
	char id;
	int index;
	bool isActive;
	int messageInSecond;
public:		
	camera();
	camera(char id);
	~camera();
	int getIndex();
	baseMessage** arrMessage;
	buffer buffer;	
	void generate();
	void sendToBuffer();
	void run();
	void stop();
};



