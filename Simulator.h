#pragma once
#include "baseMessage.h"
#include "camera.h"
class Simulator
{
public: 
	int size;
	camera arrcameras[];
	void start();
	Simulator();
};