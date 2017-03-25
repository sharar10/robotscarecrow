#include "mainFunc.h"

void timingFunc()
{

}

int fieldStatus()
{
	
}

bool hangarDoor(bool open)
{
	wiringPiSetup();
	
	//open pins
	pinMode(0,OUTPUT);
	pinMode(1,OUTPUT);
	
	//close pins
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	
	digitalWrite(0, LOW);
	digitalWrite(1, LOW);
	digitalWrite(2, LOW);
	digitalWrite(3, LOW);
	
	//open door
	if(open)
	{
		digitalWrite(0, HIGH);
		digitalWrite(1, HIGH);
		delay(500);		//need to experiment for exact delay time
		digitalWrite(0, LOW);
		digitalWrite(1, LOW);
		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		delay(1000);
		return true;
	}
	
	//close door
	else if(!open)
	{
		digitalWrite(2, HIGH);
		digitalWrite(3, HIGH);
		delay(500);		//need to experiment for exact delay time
		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(0, LOW);
		digitalWrite(1, LOW);
		delay(1000);
		return false;
	}
}
