#include "Conditioner.h"
#include <iostream>
#include <string>
using namespace std;


Conditioner::Conditioner()
{
	firm_ = "";
	model_ = "";
	weight_ = 0;
	year_ = 0;
	power_ = 0;
};

Conditioner::~Conditioner()
{}

Conditioner::Conditioner(string firm, string model, int weight, int year, int power, int temperature, string mode) :
	temperature_(temperature), mode_(mode)
{
	firm_ = firm;
	model_ = model;
	weight_ = weight;
	year_ = year;
	power_ = power;
}

void Conditioner::decreaseTemp()
{
	if (working_)
	{
		temperature_ -= 1;
		this->control(temperature_);
	}
	else cout << "Conditioner is turned off. Use turn_on command" << endl;
}

void Conditioner::increaseTemp()
{
	if (working_)
	{
		temperature_ += 1;
		this->control(temperature_);
	}
	else cout << "Conditioner is turned off. Use turn_on command" << endl;
}

void Conditioner::turn_on()
{
	working_ = true;
}


void Conditioner::DeviceInfo()
{
	cout << "========================" << endl;
	cout << "Conditioner" << endl;
	cout << firm_ << " " << model_ << endl;
	cout << "Weight: " << weight_ << endl;
	cout << "Year of production: " << year_ << endl;
	cout << "Power: " << power_ << "(W)" << endl;
	cout << "Status: ";
	if (working_) cout << "Turned on" << endl;
	else cout << "Turned off" << endl;
	cout << "Temperature: " << temperature_ << endl;
	cout << "========================" << endl;
}

void Conditioner::control(int temperature)
{
	if (working_)
	{
		if (temperature < 25)
		{
			if (temperature <= 10)
			{
				working_ = false;
				cout << "Temperature is too low! Turning off..." << endl;
				temperature_ = 0;
			}
			else
			{
				temperature_ = temperature;
				mode_ = "Cooling";
			}
		}
		else if (temperature >= 25)
		{
			if (temperature >= 45)
			{
				working_ = false;
				cout << "Temperature is too high! Turning off..." << endl;
				temperature_ = 0;
			}
			else
			{
				temperature_ = temperature;
				mode_ = "Heating";
			}
		}
	}
	else cout << "Conditioner is turned off. Use turn_on command" << endl;
}