#include "mainFunc.h"

bool timingFunc()
{
	bool inRange = false;
	time_t t = time(NULL);
	struct tm *tm = localtime(&t);

	if (tm->tm_hour >= 6 && tm->tm_hour <= 18)
	{
		inRange = true;
	}
	else
	{
		inRange = false;
	}

	return inRange;
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
		delay(5000);		//need to experiment for exact delay time
		digitalWrite(0, LOW);
		digitalWrite(1, LOW);
		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		delay(10000);
		return true;
	}
	
	//close door
	else if(!open)
	{
		digitalWrite(2, HIGH);
		digitalWrite(3, HIGH);
		delay(5000);		//need to experiment for exact delay time
		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(0, LOW);
		digitalWrite(1, LOW);
		delay(10000);
		return false;
	}
}

bool mission(bool)
{
	
}
