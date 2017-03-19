#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "jsoncpp.cpp"
#include "json/json-forwards.h"
#include "json/json.h"
#include "weathercheck.h"

//time

using namespace std;
//need to convert this into the class and header file format
//you run the file with float inputs of (lat,long)

int main()
{
	bool checked = weathercheck::safeToFly(-71.10600149999999,42.3491402);
	cout << checked << endl;

}
