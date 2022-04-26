#include "camera.h"
#include "statusMessage.h"
#include "discoverMessage.h"
#include <random>
#include <Windows.h>
#include <stdio.h>
#include <iostream>

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
	this->arrMessage = (baseMessage**)realloc(arrMessage, sizeof(baseMessage*) * (index + 1));
	std::cout << "creat:" ;	
	std::cout << std::endl;	
		(rand() % 2 + 1 == 1) ? arrMessage[index++] = createStatusMessage() : arrMessage[index++] = createDiscoverMessage();			
}
	
void camera::stop()
{
	this->isActive = false;
}

void camera::sendToBuffer() {
	for (int i = 0; i < index; i++) {
		//std::cout << "before";
		/*this->arrMessage[i]->print();
		this->arrMessage[i]->parseBack();
		this->arrMessage[i]->parseMessage();*/
		//std::cout << "after";
		this->arrMessage[i]->print();
		this->buffer.addToBuffer(this->arrMessage[i]->getMessageBuffer());
	}
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
		std::cout <<"the id :" << this->id << " ,the messages:" << this->arrMessage << std::endl;
		
		Sleep(1000);
	}
}

camera::camera(char id) {
	this->id = id;
	this->isActive = true;
	this->index = 0;
	this->messageInSecond = 1;
	this->arrMessage = NULL;
}

camera::camera() { this->arrMessage = NULL; }

camera::~camera() {	
	free(this->arrMessage);
}

int camera::getIndex() {
	return this->index;
}
	
