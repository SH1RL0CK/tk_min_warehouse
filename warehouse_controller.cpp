#include "warehouse_controller.h"

WarehouseController::WarehouseController()
    : numberOfShelves(20)
    , numberOfRows(20)
    , numberOfCompartments(50)
    , numberOfTemperatureSensors(10)
    , dbManager(new DatabaseManager(numberOfShelves, numberOfRows, numberOfCompartments))
    , firstCompartment(dbManager->createCompartmentsList())
    , temperatureSensors(std::vector<TemperatureSensor*>(numberOfTemperatureSensors))
{
    createTemperatureSensors();
}

unsigned int WarehouseController::getNumberOfShelves() const
{
    return numberOfShelves;
}

unsigned int WarehouseController::getNumberOfRows() const
{
    return numberOfRows;
}

unsigned int WarehouseController::getNumberOfCompartments() const
{
    return numberOfCompartments;
}

ShelfCompartment *WarehouseController::getFirstCompartment() const
{
    return firstCompartment;
}

std::vector<TemperatureSensor*> WarehouseController::getTemperatureSensors() const
{
    return temperatureSensors;
}

void WarehouseController::createTemperatureSensors()
{
    for(unsigned int i = 0; i < numberOfTemperatureSensors; i++)
    {
       temperatureSensors[i] = new TemperatureSensor(i + 1);
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
        QString productName,
        unsigned int numberOfProducts
)
{
    ShelfCompartment *compartment = searchForCompartment(compartmentId);
    if (compartment != nullptr)
    {
        compartment->setPalett(new Palett(productName, numberOfProducts));
    }
    dbManager->updateCompartment(compartment);
}

void WarehouseController::editPalettInCompartment(
        unsigned int compartmentId,
        QString newProductName,
        unsigned int newNumberOfProducts
)
{
    ShelfCompartment *compartment = searchForCompartment(compartmentId);
    if (compartment != nullptr && compartment->getPalett() != nullptr)
    {
        compartment->getPalett()->productName = newProductName;
        compartment->getPalett()->numberOfProducts = newNumberOfProducts;
    }
    dbManager->updateCompartment(compartment);
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
    dbManager->updateCompartment(compartment);
}

