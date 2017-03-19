#include <wiringPi.h>
#include <iostream>

using namespace std;

int main(void)
{
	wiringPiSetup();
	
	//open pins
	pinMode(0,OUTPUT);
	pinMode(1,OUTPUT);
	
	//close pins
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	
	bool active = true;
	int move = 0; //0 = close door 1 = open door
	
	/*while(active)
	{*/
		//open door
		if(move == 1)
		{
			digitalWrite(0, HIGH);
			digitalWrite(1, HIGH);
			delay(100);		//need to experiment for exact delay time
			digitalWrite(0, LOW);
			digitalWrite(1, LOW);
			digitalWrite(2, LOW);
			digitalWrite(3, LOW);
		}
		
		//close door
		else if(move == 0)
		{
			digitalWrite(2, HIGH);
			digitalWrite(3, HIGH);
			delay(100);		//need to experiment for exact delay time
			digitalWrite(2, LOW);
			digitalWrite(3, LOW);
			digitalWrite(0, LOW);
			digitalWrite(1, LOW);
		}
		/*active = false;
	}
	active = true;*/
	return 0;
}