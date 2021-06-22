#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include <stdlib.h>
#include <time.h>
#include <QDateTime>

/**
 * @brief Diese Klasse stellt einen Temperatursensor dar
 */
class TemperatureSensor
{
private:
    unsigned int id;

public:
    TemperatureSensor(unsigned int id);
    unsigned int getId() const;
    /**
     * @brief Liefert ein Messergebniss des Sensors
     * @param temperature  Temperatur die gemessen wurde
     * @param time  Zeitpunkt der Messung
     */
    void getMeasurementResult(double &temperature, QDateTime &time);
    /**
     * @brief Simuliert eine Messung (mit einer Wahrscheinlichkeit von 1 zu 1000 übersteigt es die Grenze von -18°C
     * @return Die simulierte Temperatur
     */
    double simulateMeasurement();
};

#endif // TEMPERATURESENSOR_H
