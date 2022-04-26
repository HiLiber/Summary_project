#pragma once
class buffer
{
private:
	unsigned char** bufferM;
	int index;
public:	
	buffer();
	void addToBuffer(unsigned char*);
	unsigned char** getBuffer();
	void cleanBuffer();
	~buffer();
};

