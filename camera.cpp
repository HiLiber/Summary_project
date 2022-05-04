#include "camera.h"
#include "statusMessage.h"
#include "discoverMessage.h"
#include <random>
#include <Windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;
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
	(rand() % 2 + 1 == 1) ? arrMessage[index++] = createStatusMessage() : arrMessage[index++] = createDiscoverMessage();
}

void camera::stop()
{
	this->isActive = false;
}

void camera::sendToBuffer() {
	for (int i = 0; i < index; i++) {
		this->arrMessage[i]->parseBack();
		this->buffer.addToBuffer(this->arrMessage[i]->getMessageBuffer(), this->id);
	}
	free(this->arrMessage);
	this->arrMessage = NULL;
	this->index = 0;
}

void camera::sendToServer()
{
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) {
		cout << "Winsock Connection Failed!" << endl;
		exit(1);
	}

	string getInput = (char*)buffer.getBuffer();

	SOCKADDR_IN addr;
	int addrLen = sizeof(addr);
	IN_ADDR ipvalue;
	std::cout << "port" << this->port << std::endl;
	addr.sin_addr.s_addr = inet_addr(this->ip);
	addr.sin_port = htons(3000);
	addr.sin_family = AF_INET;
	SOCKET connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(connection, (SOCKADDR*)&addr, addrLen) == 0) {
		cout << "Connected!" << endl;
		send(connection, getInput.c_str(), getInput.length(), 0);
		cout << getInput;
	}
	else {
		cout << "Error Connecting to Host" << endl;
		exit(1);
	}
}

void camera::run() {
	while (this->isActive) {
		for (int i = 0; i < this->messageInSecond; i++) {
			this->generate();
		}
		this->sendToBuffer();
		Sleep(1000);
	}
}

camera::camera(char id, int messageInSecond) {
	/*std::cout << "in full constractor the id " <<id<< std::endl;*/
	this->id = id;
	this->isActive = true;
	this->index = 0;
	this->messageInSecond = messageInSecond;
	this->arrMessage = NULL;
	//this->ip = (char*)realloc(this->ip, sizeof(char*));
	//this->ip = (char*)"127.0.0.1";
}

camera::camera() {
	//std::cout << "in empty constractor" << std::endl;
	this->arrMessage = NULL;
}

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
