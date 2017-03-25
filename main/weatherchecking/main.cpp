#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "jsoncpp.cpp"
#include "json/json-forwards.h"
#include "json/json.h"


//time

using namespace std;
//need to convert this into the class and header file format
//you run the file with float inputs of (lat,long)

int main()
{

	string darksky = "https://api.darksky.net/forecast/d5149dd136c55362108974d2d4a41e96/";
	string latitude = "42.3491402";
	string longitude = "-71.10600149999999";
	darksky += latitude + "," + longitude;
	string todownload = "wget -O test.json -q " + darksky;
	const char * c = todownload.c_str();
	system(c);
	ifstream i("test.json");
	Json::Reader reader;
	Json::Value root;
	reader.parse(i,root);
	float precipIntensity = root["currently"]["precipIntensity"].asFloat();
	float precipProbability = root["currently"]["precipProbability"].asFloat();

	bool isSafeToFly = true;
	if ((precipIntensity > 0) || (precipProbability > 0)) 
		isSafeToFly = false;

	cout << precipIntensity << " " << precipProbability << endl;
	if (isSafeToFly) cout << "It's safe to fly" << endl;
	return 0;
}


bool weatherIsGood(string latitude, string longitude) {
	string darksky = "https://api.darksky.net/forecast/d5149dd136c55362108974d2d4a41e96/";
	
	darksky += latitude + "," + longitude;
	string todownload = "wget -O test.json -q " + darksky;
	const char * c = todownload.c_str();
	system(c);
	ifstream i("test.json");
	Json::Reader reader;
	Json::Value root;
	reader.parse(i,root);
	float precipIntensity = root["currently"]["precipIntensity"].asFloat();
	float precipProbability = root["currently"]["precipProbability"].asFloat();

	bool isSafeToFly = true;
	if ((precipIntensity > 0) || (precipProbability > 0)) 
		isSafeToFly = false;

	cout << precipIntensity << " " << precipProbability << endl;
	if (isSafeToFly) cout << "It's safe to fly" << endl;
	return 0;
}
