#include "warehouse_controller.h"
#include <QDebug>

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
    : numberOfShelves(20)
    , numberOfRows(20)
    , numberOfCompartments(50)
    , firstCompartment(nullptr)
{
    createWarehouseList();
}

void WarehouseController::setFirstCompartment(ShelfCompartment *_firstCompartment)
{
    firstCompartment = _firstCompartment;
}

ShelfCompartment *WarehouseController::getFirstCompartment() const
{
    return firstCompartment;
}

void WarehouseController::createWarehouseList()
{
    unsigned int firstCompartmentId = 10101;
    firstCompartment = new ShelfCompartment(firstCompartmentId);
    ShelfCompartment *tmpCompartment = firstCompartment;
    for (unsigned int i = 1; i <= numberOfShelves; i++)
    {
        for (unsigned int j = 1; j <= numberOfRows; j++)
        {
            for (unsigned int k = 1; k <= numberOfCompartments; k++)
            {
                unsigned int compartmentId = i * 10000 + j * 100 + k;
                if (compartmentId == firstCompartmentId)
                {
                    continue;
                }
                tmpCompartment->nextCompartment = new ShelfCompartment(compartmentId);
                tmpCompartment = tmpCompartment->nextCompartment;
            }
        }
    }
}

ShelfCompartment *WarehouseController::searchForCompartment(unsigned int id)
{
    ShelfCompartment *tmpCompartment = firstCompartment;
    while (tmpCompartment != nullptr)
    {
        if (tmpCompartment->id == id)
        {
            return tmpCompartment;
        }
        tmpCompartment = tmpCompartment->nextCompartment;
    }
    return nullptr;
}

void WarehouseController::storePalettInCompartment(
        unsigned int compartmentId,
        ProductType productType,
        QString productName,
        unsigned int numberOfProducts
)
{
    ShelfCompartment *compartment = searchForCompartment(compartmentId);
    if (compartment != nullptr)
    {
        compartment->palett = new Palett(productType, productName, numberOfProducts);
    }
}

void WarehouseController::editPalettInCompartment(
        unsigned int compartmentId,
        ProductType newProductType,
        QString newProductName,
        unsigned int newNumberOfProducts
)
{
    ShelfCompartment *compartment = searchForCompartment(compartmentId);
    if (compartment != nullptr && compartment->palett != nullptr)
    {
        compartment->palett->productType = newProductType;
        compartment->palett->productName = newProductName;
        compartment->palett->numberOfProducts = newNumberOfProducts;
    }
}

void WarehouseController::removePalettFromCompartment(unsigned int compartmentId)
{
    ShelfCompartment *compartment = searchForCompartment(compartmentId);
    Palett *palett = compartment->palett;
    if (compartment != nullptr && palett != nullptr)
    {
        compartment->palett = nullptr;
        delete palett;
    }
}

