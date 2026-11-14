#include "PIDController.h"
#include <Arduino.h>
PIDController :: PIDController(float p, float i, float d, float min_out, float max_out ):
    kp(p), ki(i), kd(d), min_output(min_out), max_output(max_out), integral(0.0f),prev_error(0.0f),last_time(0) {}

float PIDController :: compute(float current_temperature)
{
    unsigned long now = millis();
    float dt = (now -last_time)/1000.0f;
    float error = PIDController::computeError(current_temperature);

    if (dt <= 0.0f) return error * kp;

    float P = kp * error;
    integral += error * dt;
    float I = ki * integral;
    float derative = (error - prev_error)/dt;
    float D = kd * derative;
    float current_output = P+I+D;

    if (current_output > max_output) current_output = max_output;
    else if ( current_output < min_output) current_output = min_output;

    prev_error = error;
    last_time = now;

    return current_output;
}
        
void PIDController::reset()
{
    prev_error = 0.0f;
    integral = 0.0f;
    last_time = millis();
}
   
