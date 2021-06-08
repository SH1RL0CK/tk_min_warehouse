#ifndef SHELFCOMPARTMENT_H
#define SHELFCOMPARTMENT_H

#include <QString>

enum ProductType { IceCream, Pizza };

struct Palett
{
    ProductType productType;
    QString productName;
    unsigned int numberOfProducts;
    Palett(ProductType _productType, QString _productName, unsigned int _numberOfProducts);
};

class ShelfCompartment
{
private:
    unsigned int id;
    Palett *palett;
    ShelfCompartment *nextCompartment;
public:
    ShelfCompartment(unsigned int _id);
    void setPalett(Palett *_palett);
    void setNextCompartment(ShelfCompartment *_nextCompartment);
    unsigned int getId() const;
    Palett *getPalett() const;
    ShelfCompartment *getNextCompartment() const;
    static int createId(unsigned int shelfNumber, unsigned int rowNumber,  unsigned int compartmentNumber);
};

#endif // SHELFCOMPARTMENT_H
