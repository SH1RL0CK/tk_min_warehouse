#include "temperature_sensor.h"

TemperatureSensor::TemperatureSensor(unsigned int _id)
    : id(_id)
{
     srand(time(NULL));
}

void TemperatureSensor::getMeasurementResult(double &temperature, QDateTime &time)
{
    temperature = simulateMeasurement();
    time = QDateTime::currentDateTime();
}

double TemperatureSensor::simulateMeasurement()
{
    double temperature = 0.0;
    if((rand() % 1000 + 1) == 1){
        temperature = (((rand() % 49) + 1751)/100.0) * -1;
    }else{
        temperature = (((rand() % 50) + 1801)/100.0) * -1;
    }
    return temperature;
}
