#pragma once
#include "Device.h"
#include "IControllable.h"
class Conditioner :
    public Device, public IControllable
{
public:

    Conditioner();
    Conditioner(string firm, string model, int weight, int year, int power, int temperature, string mode);
    ~Conditioner();


    void decreaseTemp();
    void increaseTemp();
    void turn_on();

    void DeviceInfo() override;
    void control(int tempetarure) override;

private:
    int temperature_;
    string mode_;
};

