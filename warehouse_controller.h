#ifndef WAREHOUSECONTROLLER_H
#define WAREHOUSECONTROLLER_H

#include <QString>

enum ProductType { IceCream, Pizza };

struct Palett
{
    ProductType productType;
    QString productName;
    unsigned int numberOfProducts;
    Palett(ProductType _productType, QString _productName, unsigned int _numberOfProducts);
};

struct ShelfCompartment
{
    unsigned int id;
    Palett *palett;
    ShelfCompartment *nextCompartment;
    ShelfCompartment(unsigned int _id);
};

class WarehouseController
{
private:
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
