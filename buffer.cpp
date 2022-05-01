#include "buffer.h"
#include <Windows.h>
buffer::buffer()
{
	this->bufferM = nullptr;
	this->index = 0;
}

void buffer::addToBuffer(unsigned char* message)
{
	this->bufferM = (unsigned char**)realloc(this->bufferM, sizeof(unsigned char*) * (index + 1));
	this->bufferM[index++] = message;
}

unsigned char** buffer::getBuffer()
{
	return this->bufferM;
}

void buffer::cleanBuffer()
{	
	this->bufferM = nullptr;
}

int buffer::getIndex()
{
	return this->index;
}

buffer::~buffer() {

	free(this->bufferM);
}
