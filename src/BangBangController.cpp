#include "BangBangController.h"

BangBangController ::  BangBangController(float h):
    hysteresis(h), current_output(0.0f) {}

float BangBangController::compute(float current_temperature)
{
    float error = TemperatureController::computeError(current_temperature);
    if ( error > hysteresis)
    { 
        current_output = 100.0f; // heating on
    }else if( error < -hysteresis)
    {
        current_output= 0.0f; // heating off
    }
    return current_output;
}


