#pragma once
#include <string>
using namespace std;
class Device
{
public:
	virtual void DeviceInfo() = 0;
	virtual ~Device() {}


	bool working_ = false;
	string firm_;
	string model_;
	int weight_;
	int year_;
	int power_;
};

