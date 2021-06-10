#ifndef WAREHOUSECONTROLLER_H
#define WAREHOUSECONTROLLER_H

#include <vector>
#include <QString>
#include "shelf_compartment.h"

class WarehouseController
{
private:
    unsigned int numberOfShelves;
    unsigned int numberOfRows;
    unsigned int numberOfCompartments;
    ShelfCompartment *firstCompartment;
public:
    WarehouseController();
    ShelfCompartment *getFirstCompartment() const;
    void createWarehouseList();
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
