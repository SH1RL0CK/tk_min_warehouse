#ifndef WAREHOUSECONTROLLER_H
#define WAREHOUSECONTROLLER_H

#include <vector>
#include <QString>
#include "shelf_compartment.h"
#include "temperature_sensor.h"

class WarehouseController
{
private:
    unsigned int numberOfShelves;
    unsigned int numberOfRows;
    unsigned int numberOfCompartments;
    unsigned int numberOfTemperatureSensors;

    ShelfCompartment *firstCompartment;
    std::vector<TemperatureSensor*> temperatureSensors;
public:
    WarehouseController();
    ShelfCompartment *getFirstCompartment() const;
    std::vector<TemperatureSensor*> getTemperatureSensors() const;
    void createWarehouseList();
    void createTemperatureSensors();
    ShelfCompartment *searchForCompartment(unsigned int id);
    void storePalettInCompartment(
            unsigned int compartmentId,
            QString productName,
            unsigned int numberOfProducts
     );
    void editPalettInCompartment(
            unsigned int compartmentId,
            QString newProductName,
            unsigned int newNumberOfProducts
     );
    void removePalettFromCompartment(unsigned int compartmentId);
};

#endif // WAREHOUSECONTROLLER_H
