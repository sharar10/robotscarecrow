#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "jsoncpp.cpp"
#include "json/json-forwards.h"
#include "json/json.h"

using namespace std;

bool safeToFly(string longitude, string latitude) {
    string darksky = "https://api.darksky.net/forecast/d5149dd136c55362108974d2d4a41e96/";
	string Longitude = longitude;
	string Latitude = latitude;
	darksky += Longitude + "," + Latitude;
	string todownload = "wget -O test.json " + darksky;
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

	// cout << root["currently"]["nearestStormDistance"] << endl;
	// cout << nearestStormDistance << " " << precipIntensity << " " << precipProbability << endl;
	// cout << safeToFly << endl;

	return safeToFly;


                                                                                    
}