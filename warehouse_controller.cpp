#include "warehouse_controller.h"

Palett::Palett(ProductType _productType, QString _productName, unsigned int _numberOfProducts)
    : productType(_productType)
    , productName(_productName)
    , numberOfProducts(_numberOfProducts)
{}

ShelfCompartment::ShelfCompartment(unsigned int _id)
    : id(_id)
    , palett(nullptr)
    , nextCompartment(nullptr)
{}

WarehouseController::WarehouseController()
    : firstCompartment(nullptr)
{}

ShelfCompartment *WarehouseController::getFirstCompartment() const
{
    return firstCompartment;
}

void WarehouseController::setFirstCompartment(ShelfCompartment *_firstCompartment)
{
    firstCompartment = _firstCompartment;
}
