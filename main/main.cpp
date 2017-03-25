#include <iostream>
#include <string>
#include <wiringPi.h> NO WIRING PI FOR THE TIME BEING
#include <time.h>
#include "mainFunc.h"

using namespace std;

int main()
{
	bool system = true;
	while(system){
		//server code
		bool active = timingFunc();
		while(active){
			int coordinate = 0; //sent to iOS
			bool openDoor = false;	//open door = true close door = false
			bool opened = false;	//notifies when doors are fully open
			bool success = false;	//successful mission (not sure if we need this)
			bool appReady = false;
			
			if(appReady)
			{
				//mission starts
				coordinate = fieldStatus();
				opened = hangarDoor(openDoor);
				success = mission(opened);
				
			}
			else
			{
				active = false;
				//some error message
			}
		}
	}
	return 0;
}

