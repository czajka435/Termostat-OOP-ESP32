#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H
#include "TemperatureController.h"

class PIDController : public TemperatureController
{
private:
    float ki, kp, kd;
    float min_output, max_output;
    float integral, prev_error;
    unsigned long last_time;    
public:
    PIDController(float p, float i, float d, float min_out, float max_out);
    ~PIDController() = default;
    float compute(float current_temperature) override;
    void reset(); //clear memory integral and error
}; 

#endif // PID_CONTROLLER_H