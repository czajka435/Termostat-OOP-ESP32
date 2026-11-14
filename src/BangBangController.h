#ifndef Bang_Bang_Controller_H
#define Bang_Bang_Controller_H
#include "TemperatureController.h"

class BangBangController : public TemperatureController
{
private:
    float hysteresis, current_output;

public:
    BangBangController(float h);
    ~BangBangController() = default;
    float compute(float current_temperature) override;
};


#endif // Bang_Bang_Controller_H
