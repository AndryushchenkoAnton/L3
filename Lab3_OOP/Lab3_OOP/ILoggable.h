#pragma once
using namespace std;
#include <iostream>

class ILoggable {
public:
	virtual void logToScreen() = 0;
	virtual void logToFile(const string& filename) = 0;
};

