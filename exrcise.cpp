// exrcise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Simulator.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment (lib, "Ws2_32.lib")
#include <iostream>
#include <string.h>
#include <sstream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	Simulator s = Simulator();
	fstream newfile;	
	newfile.open("config.txt", ios::in); 
	if (newfile.is_open()) { 		
		string tp;
		int i = 0;
		while (getline(newfile, tp)) {
			std::cout << "i" << i++;
			string key = tp.substr(0, tp.find(':'));
			string num = tp.substr(tp.find(':') + 1);			
			/*switch (key)
			{
			case "numOfCameras":
				s.size =  stoi(num);
				break;
			case "messageInSecond":
				s.arrcameras[0].messageInSecond= stoi(num);
				break;
			case "ip":
				s.arrcameras[0].ip = num.c_str();
				break;
			case "port":
				s.arrcameras[0].port = stoi(num);
				break;
			default:
				break;
			}*/
			if (key == "numOfCameras") {
				std::cout << "in sizeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee:" << stoi(num);
				s.size = stoi(num);
			}
			else {
				if (key == "messageInSecond") {
					s.arrcameras[0].messageInSecond = stoi(num);
				}
				else {
					if (key == "ip") {
						for (int i = 0; i < s.size; i++) {
							s.arrcameras[i].ip = num.c_str();
							std::cout << "ippp" << s.arrcameras[i].ip;
						}
					}						
					else {
						if (key == "port") {							
							for (int i = 0; i < s.size; i++) {						
								s.arrcameras[i].port = stoi(num);
								std::cout << "porttt" << s.arrcameras[i].port;
							}					

						}
					}
				}

			}

		}

	}
	newfile.close();
	s.start();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
