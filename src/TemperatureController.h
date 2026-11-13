#ifndef TEMPERATURE_CONTROLLER_H
#define TEMPERATURE_CONTROLLER_H

class TemperatureController
{
protected:
    float target_temperature;
public:
    virtual ~TemperatureController()=default;
    TemperatureController() : target_temperature(0.0f) {}
    virtual float compute(float current_temperature) = 0;
    void setTarget(float target) 
    {
        target_temperature = target;
    }

    float computeError(float current_temperature)
    {
            return target_temperature - current_temperature;
    }  
};

#endif // TEMPERATURE_CONTROLLER_H




