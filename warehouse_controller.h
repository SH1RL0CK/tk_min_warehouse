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

class WarehouseController
{
public:
    WarehouseController();
};

#endif // WAREHOUSECONTROLLER_H
