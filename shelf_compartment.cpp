#include "shelf_compartment.h"

Palett::Palett(QString _productName, unsigned int _numberOfProducts)
    : productName(_productName)
    , numberOfProducts(_numberOfProducts)
{}

ShelfCompartment::ShelfCompartment(unsigned int _id)
    : id(_id)
    , palett(nullptr)
    , nextCompartment(nullptr)
{}

void ShelfCompartment::setNextCompartment(ShelfCompartment *_nextCompartment)
{
    nextCompartment = _nextCompartment;
}

void ShelfCompartment::setPalett(Palett *_palett)
{
    palett = _palett;
}

unsigned int ShelfCompartment::getId() const
{
    return id;
}

Palett *ShelfCompartment::getPalett() const
{
    return palett;
}

ShelfCompartment *ShelfCompartment::getNextCompartment() const
{
    return nextCompartment;
}

int ShelfCompartment::createId(unsigned int shelfNumber, unsigned int rowNumber, unsigned int compartmentNumber)
{
    return shelfNumber * 10000 + rowNumber * 100 + compartmentNumber;
}
