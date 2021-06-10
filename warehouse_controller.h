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
    std::vector<QString> productTypes;
    std::vector<QString> iceCreams;
    std::vector<QString> pizzas;
    ShelfCompartment *firstCompartment;
public:
    WarehouseController();
    std::vector<QString> getProductTypes() const;
    std::vector<QString> getPizzas() const;
    std::vector<QString> getIceCreams() const;
    ShelfCompartment *getFirstCompartment() const;
    void createWarehouseList();
    ShelfCompartment *searchForCompartment(unsigned int id);
    void storePalettInCompartment(
            unsigned int compartmentId,
            QString productType,
            QString productName,
            unsigned int numberOfProducts
     );
    void editPalettInCompartment(
            unsigned int compartmentId,
            QString newProductType,
            QString newProductName,
            unsigned int newNumberOfProducts
     );
    void removePalettFromCompartment(unsigned int compartmentId);
};

#endif // WAREHOUSECONTROLLER_H
