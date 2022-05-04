#pragma once
class buffer
{
private:
	unsigned char** bufferM;
	int index;
public:
	buffer();
	void addToBuffer(unsigned char*,int id);
	unsigned char** getBuffer();
	void cleanBuffer();
	int getIndex();
	~buffer();
};

