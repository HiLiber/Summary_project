#include "Simulator.h"
#include <iostream>
#include <stdio.h>
#include <thread>
void Simulator::start()
{
	std::thread cameraThreds[4];
	std::cout << "the size:" << this->size << std::endl;
	for (int i = 0; i < size; i++) {
		cameraThreds[i] = std::thread(&camera::run, arrcameras[i]);	
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < arrcameras[i].getIndex(); j++) {
			std::cout << "before  : "<<std::endl;
			arrcameras[i].arrMessage[j]->print();
			arrcameras[i].arrMessage[j]->parseMessage();
			std::cout << "after  : ";
			arrcameras[i].arrMessage[j]->print();
		}
	}
}

Simulator::Simulator(){	
	this->size = 4;
	int i=1;
	for (int i = 0; i < 1; i++) {		
		arrcameras[i] = camera((char)i++);
	}
}
