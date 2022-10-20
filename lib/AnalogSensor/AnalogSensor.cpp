#include <AnalogSensor.h>


void AnalogSensor::setup(unsigned int pin,float (*equation)(float,float[],uint8_t),float coeff[],uint8_t)
{    
    this ->_pin = pin;
    _equation = equation;
    _coeff = coeff;
    _num_coef = _num_coef;
    pinMode(_pin,INPUT);
    
}

float AnalogSensor::read()
{
    _digital_level = analogRead(_pin);
    _sensor_measurement = _equation((float)analogRead(_pin),_coeff,_num_coef);    
    return _sensor_measurement;
}

float AnalogSensor::getMesaurement(measurement type)
{
    switch (type)
    {
    case DIGITAL_LEVEL:
        return _digital_level;
        break;
    case SENSOR_MEASUREMENT:
        return _sensor_measurement;
        break;

    default:
        return _digital_level;
        break;
    }

}
