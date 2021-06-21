#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include <stdlib.h>
#include <time.h>
#include <QDateTime>

class TemperatureSensor
{
private:
    unsigned int id;

public:
    TemperatureSensor(unsigned int id);
    void getMeasurementResult(double &temperature, QDateTime &time);
    double simulateMeasurement();
};

#endif // TEMPERATURESENSOR_H
