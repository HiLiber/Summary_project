#include "Simulator.h"
#include <iostream>
#include <stdio.h>
#include <thread>
#include <Windows.h>
void Simulator::start()
{
	std::thread cameraThreds[4];
	std::cout << "the size:" << this->size << std::endl;
	for (int i = 0; i < size; i++) {
		cameraThreds[i] = std::thread(&camera::run, &arrcameras[i]);	
	}
	/*Sleep(2000);*/
	while (true) {
		for (int i = 0; i < size; i++) {
			std::cout << "out for the index" << arrcameras[i].getIndex() << " the id" << arrcameras[i].getid() << std::endl;
	}
		Sleep(1000);
	/*for (int i = 0; i < size; i++) {
		std::cout << "out for the index" << arrcameras[i].getIndex()<<" the id" << arrcameras[i].getid() << std::endl;*/
		//for (int j = 0; j < arrcameras[i].getIndex(); j++) {
			/*std::cout << "in for" << std::endl;
			std::cout << "before simulator : "<<std::endl;
			arrcameras[i].arrMessage[j]->print();
			arrcameras[i].arrMessage[j]->parseMessage();
			std::cout << "after simulator : ";
			arrcameras[i].arrMessage[j]->print();*/
			//std::cout << arrcameras[i].buffer.getBuffer();
		//}
	}
}

Simulator::Simulator(){	
	this->size = 4;
	char id='a';
	for (int i = 0; i < 4; i++) {		
		arrcameras[i] = camera(id++,10);
	}
}
