#include "camera.h"
#include "statusMessage.h"
#include "discoverMessage.h"
#include <random>
#include <Windows.h>
#include <stdio.h>
#include <iostream>

//#include "stdafx.h"
//#include <tchar.h>
//#using <mscorlib.dll>
//#using <System.xml.dll>
//using namespace System;
//using namespace System::Xml;

statusMessage* createStatusMessage()
{
	static int id = 1;
	id++;
	statusMessage* sm = new statusMessage(id, 1, rand() % 3 + 1);
	return sm;
}

discoverMessage* createDiscoverMessage()
{
	static int id = 100;
	id++;
	discoverMessage* dm = new discoverMessage(id, 2, rand() % 9500 + 500, rand() % 361, rand() % 1001);
	return dm;
}

void camera::generate()
{
	std::cout << "id:" << this->id << " index:" << this->index<<std::endl;
	this->arrMessage = (baseMessage**)realloc(arrMessage, sizeof(baseMessage*) * (index + 1));
	/*std::cout << "creat:" ;	
	std::cout << std::endl;	*/
		(rand() % 2 + 1 == 1) ? arrMessage[index++] = createStatusMessage() : arrMessage[index++] = createDiscoverMessage();			
}
	
void camera::stop()
{
	this->isActive = false;
}

void camera::sendToBuffer() {	
	for (int i = 0; i < index; i++) {
		//std::cout << "before id:"<<this->id<<std::endl;
		//this->arrMessage[i]->print();		
		//this->arrMessage[i]->parseMessage();
		//std::cout << "after id:"<<this->id<<std::endl;
		////std::cout << "the id:" << this->id;
		//this->arrMessage[i]->print();
		this->arrMessage[i]->parseBack();
		this->buffer.addToBuffer(this->arrMessage[i]->getMessageBuffer());
		std::cout << "messagebuffer" << this->arrMessage[i]->getMessageBuffer();
	}
	std::cout << "index buffer:" << this->buffer.getIndex()<<"id:"<<this->id<<std::endl;
	free(this->arrMessage);
	this->arrMessage = NULL;
	this->index = 0;
}

void camera::run() {
	while (this->isActive) {
		for (int i = 0; i < this->messageInSecond; i++) {
			this->generate();
			//this->arrMessage[index - 1]->print();
		}
		this->sendToBuffer();
		//std::cout <<"the id :" << this->id << " ,the messages:" << this->arrMessage << std::endl;		
		Sleep(1000);
	}
}

camera::camera(char id,int messageInSecond) {
	/*std::cout << "in full constractor the id " <<id<< std::endl;*/
	this->id = id;
	this->isActive = true;
	this->index = 0;
	this->messageInSecond = messageInSecond;
	this->arrMessage = NULL;
}

camera::camera() {
	//std::cout << "in empty constractor" << std::endl;
	this->arrMessage = NULL; }

camera::~camera() {	
	free(this->arrMessage);
}

int camera::getIndex() {
	return this->index;
}

char camera::getid()
{
	return this->id;
}
