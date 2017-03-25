#include <iostream>
#include <string>
#include <wiringPi.h>
#include "mainFunc.h"

using namespace std;

int main()
{
	//server code
	int coordinate = 0; //sent to iOS
	bool active = false; //from iOS
	bool openDoor = false;	//open door = true close door = false
	bool opened = false;	//notifies when doors are fully open
	bool success = false;	//successful mission (not sure if we need this)
	
	if(active)
	{
		//mission starts
		coordinate = fieldStatus();
		opened = hangarDoor(openDoor);
		success = mission(opened);
	}
	else
	{
		//some error message
	}
	return 0;
}

