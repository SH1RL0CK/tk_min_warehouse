#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#include <QDateTime>

class TemperatureSensor
{
private:
    int id;

public:
    TemperatureSensor();
    void getMeasurementResult(float &temperature, QDateTime &time);
    float simulateMeasurement();
};

#endif // TEMPERATURESENSOR_H
