#pragma once
#include "Device.h"
#include "IControllable.h"
class Heater :
    public Device, public IControllable
{
public:

    Heater();
    Heater(string firm, string model, int weight, int year, int power, int temperature);
    ~Heater();


	void decreaseTemp();
	void increaseTemp();
	void turn_on();

    void DeviceInfo() override;
    void control(int tempetarure) override;

private:
    int temperature_;
    string mode_ = "Heating";
};

