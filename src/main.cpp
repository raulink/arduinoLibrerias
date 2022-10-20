#include <Arduino.h>
#include <AnalogSensor.h>
#include <Equations.h>

AnalogSensor sensor;
unsigned long current_time, prev_time;
const uint8_t SENSOR_PIN = 33;
float coefficients[]={0.0f,0.00086f};

uint16_t dt_ms = 500;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  sensor.setup(SENSOR_PIN,polynomial,coefficients,sizeof(coefficients)/sizeof(coefficients[0]));
  prev_time = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(sensor.read());
  current_time = millis();
  if(current_time - prev_time>dt_ms)
  {
    prev_time = current_time;
    sensor.read();
    Serial.printf("%d, %.2f \n", (uint16_t) sensor.getMesaurement(),sensor.getMesaurement(SENSOR_MEASUREMENT));
  }
}