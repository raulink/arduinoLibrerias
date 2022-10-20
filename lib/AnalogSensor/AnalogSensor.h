#ifndef __ANALOGSENSOR_H__
#define __ANALOGSENSOR_H__
#include <Arduino.h>

enum measurement{
    DIGITAL_LEVEL,
    SENSOR_MEASUREMENT
};

class AnalogSensor{
    public:
        AnalogSensor();
        ~AnalogSensor();
        void setup(unsigned int pin,float (*equation)(float,float[],uint8_t),float coeff[],uint8_t);
        float read();

        float getMesaurement(measurement type=DIGITAL_LEVEL);
        
    private:
        uint8_t _pin;
        float (*_equation)(float,float[],uint8_t);
        float *_coeff;
        uint8_t _num_coef;
    protected:
        uint16_t _digital_level;
        float _sensor_measurement;
};
#endif // __ANALOGSENSOR_H__