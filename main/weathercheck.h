#ifndef WEATHERCHECKHPP
#define WEATHERCHECKHPP

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "jsoncpp.cpp"
#include "json/json-forwards.h"
#include "json/json.h"

using namespace std;

bool safeToFly(string longitude, string latitude);  