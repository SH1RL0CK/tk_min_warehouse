#include "warehouse_controller.h"

WarehouseController::WarehouseController()
    : numberOfShelves(20)
    , numberOfRows(20)
    , numberOfCompartments(50)
    , productTypes({
        "Pizza",
        "Eis"
      })
    , iceCreams({
        "Erdbeereis",
        "Schokoladeneis",
        "Stracciatellaeis",
        "Vanilleeis"
      })
    , pizzas({
         "Pizza Hawaii"
         "Pizza Margherita",
         "Pizza Salami",
         "Pizza Schinken"
      })
    , firstCompartment(nullptr)
{
    createWarehouseList();
}

std::vector<QString> WarehouseController::getProductTypes() const
{
    return productTypes;
}

std::vector<QString> WarehouseController::getIceCreams() const
{
    return iceCreams;
}

std::vector<QString> WarehouseController::getPizzas() const
{
    return pizzas;
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
                unsigned int compartmentId = ShelfCompartment::createId(i, j, k);
                if (compartmentId == firstCompartmentId)
                {
                    continue;
                }
                tmpCompartment->setNextCompartment(new ShelfCompartment(compartmentId));
                tmpCompartment = tmpCompartment->getNextCompartment();
            }
        }
    }
}

ShelfCompartment *WarehouseController::searchForCompartment(unsigned int id)
{
    ShelfCompartment *tmpCompartment = firstCompartment;
    while (tmpCompartment != nullptr)
    {
        if (tmpCompartment->getId() == id)
        {
            return tmpCompartment;
        }
        tmpCompartment = tmpCompartment->getNextCompartment();
    }
    return nullptr;
}

void WarehouseController::storePalettInCompartment(
        unsigned int compartmentId,
        QString productType,
        QString productName,
        unsigned int numberOfProducts
)
{
    ShelfCompartment *compartment = searchForCompartment(compartmentId);
    if (compartment != nullptr)
    {
        compartment->setPalett(new Palett(productType, productName, numberOfProducts));
    }
}

void WarehouseController::editPalettInCompartment(
        unsigned int compartmentId,
        QString newProductType,
        QString newProductName,
        unsigned int newNumberOfProducts
)
{
    ShelfCompartment *compartment = searchForCompartment(compartmentId);
    if (compartment != nullptr && compartment->getPalett() != nullptr)
    {
        compartment->getPalett()->productType = newProductType;
        compartment->getPalett()->productName = newProductName;
        compartment->getPalett()->numberOfProducts = newNumberOfProducts;
    }
}

void WarehouseController::removePalettFromCompartment(unsigned int compartmentId)
{
    ShelfCompartment *compartment = searchForCompartment(compartmentId);
    Palett *palett = compartment->getPalett();
    if (compartment != nullptr && palett != nullptr)
    {
        compartment->setPalett(nullptr);
        delete palett;
    }
}

