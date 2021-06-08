#ifndef WAREHOUSECONTROLLER_H
#define WAREHOUSECONTROLLER_H

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
    void setFirstCompartment(ShelfCompartment *_firstCompartment);
    ShelfCompartment *getFirstCompartment() const;
    void createWarehouseList();
    ShelfCompartment *searchForCompartment(unsigned int id);
    void storePalettInCompartment(
            unsigned int compartmentId,
            ProductType productType,
            QString productName,
            unsigned int numberOfProducts
     );
    void editPalettInCompartment(
            unsigned int compartmentId,
            ProductType newProductType,
            QString newProductName,
            unsigned int newNumberOfProducts
     );
    void removePalettFromCompartment(unsigned int compartmentId);
};

#endif // WAREHOUSECONTROLLER_H
