#include "Heater.h"
#include <iostream>
#include <string>
using namespace std;


Heater::Heater()
{
	firm_ = "";
	model_ = "";
	weight_ = 0;
	year_ = 0;
	power_ = 0;
};

Heater::~Heater()
{}

Heater::Heater(string firm, string model, int weight, int year, int power, int temperature) :
	temperature_(temperature)
{
	firm_ = firm;
	model_ = model;
	weight_ = weight;
	year_ = year;
	power_ = power;
}
void Heater::decreaseTemp()
{
	if (working_)
	{
		temperature_ -= 1;
		this->control(temperature_);
	}
	else cout << "Heater is turned off. Use turn_on command" << endl;
}

void Heater::increaseTemp()
{
	if (working_)
	{
		temperature_ += 1;
		this->control(temperature_);
	}
	else cout << "Heater is turned off. Use turn_on command" << endl;
}

void Heater::turn_on()
{
	working_ = true;
}

void Heater::DeviceInfo()
{
	cout << "========================" << endl;
	cout << "Heater" << endl;
	cout << firm_ << " " << model_ << endl;
	cout << "Weight: " << weight_ << endl;
	cout << "Year of production: " << year_ << endl;
	cout << "Power: " << power_ << "(W)" << endl;
	cout << "Status: ";
	if (working_) cout << "Turned on" << endl;
	else cout << "Turned off" << endl;
	cout << "Temperature: " << temperature_ << endl;
	cout << "========================";
}

void Heater::control(int temperature)
{
	if (working_)
	{
		if (temperature <= 10)
		{
			working_ = false;
			cout << "Temperature is too low! Turning off..." << endl;
			temperature_ = 0;
		}
		if (temperature >= 25)
		{
			if (temperature >= 45)
			{
				working_ = false;
				cout << "Temperature is too high! Turning off..." << endl;
				temperature_ = 0;
			}
			else temperature_ = temperature;
		}
		else cout << "Temperature is too low for heater. Please, set another" << endl;
	}
	else cout << "Conditioner is turned off. Use turn_on command" << endl;
}