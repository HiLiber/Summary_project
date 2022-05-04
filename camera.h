#pragma once
#include "baseMessage.h"
#include "buffer.h"
#include <stdio.h>
#include <iostream>
class camera
{
private:
	char id;
	int index;
	bool isActive;
	
public:		
	camera();
	camera(char id,int messageInSecond);
	~camera();
	const char* ip;
	int port;
	int messageInSecond;
	int getIndex();
	char getid();
	baseMessage** arrMessage;
	buffer buffer;	
	void generate();
	void sendToBuffer();
	void sendToServer();
	void run();
	void stop();
};



