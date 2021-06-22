#ifndef SHELFCOMPARTMENT_H
#define SHELFCOMPARTMENT_H

#include <QString>

/**
 * @brief Stellt die Palette dar, die in einem Regalfach liegen kann
 */
struct Palett
{
    /**
     * @brief Name des Produkts, was auf der Palette gelagert wird
     */
    QString productName;
    /**
     * @brief Anzahl des Produkts, was auf der Palette gelagert wird
     */
    unsigned int numberOfProducts;
    Palett(QString _productName, unsigned int _numberOfProducts);
};

class ShelfCompartment
{
private:
    /**
     * @brief Jedes Fach hat eine ID. Diese wird wie folgt berechnet:
     *        10000 * Regalnummer + 100 * Regalbodennummer + Regalfachnummer
     */
    unsigned int id;
    /**
     * @brief Palette in dem Regalfach (ist ein Nullpointer wenn hier keine lagert)
     */
    Palett *palett;
    /**
     * @brief nächstes Element in der Liste
     */
    ShelfCompartment *nextCompartment;
public:
    ShelfCompartment(unsigned int _id);
    void setPalett(Palett *_palett);
    void setNextCompartment(ShelfCompartment *_nextCompartment);
    unsigned int getId() const;
    Palett *getPalett() const;
    ShelfCompartment *getNextCompartment() const;
    /**
     * @brief Die genaue Position des Regalfachs aus der Id extraieren
     * @param shelfNumber  Die Regalnummer
     * @param rowNumber  Die Regalbodennummer
     * @param compartmentNumber  Die Regalfachnummer
     */
    void extractLocationFromId(unsigned int &shelfNumber, unsigned int &rowNumber, unsigned int &compartmentNumber);
    /**
     * @brief Berechnung der Id aus der Position des Lagers
     * @param shelfNumber  Die Regalnummer
     * @param rowNumber  Die Regalbodennummer
     * @param compartmentNumber  Die Regalfachnummer
     * @return Die erzeugte Id
     */
    static int createId(unsigned int shelfNumber, unsigned int rowNumber,  unsigned int compartmentNumber);
};

#endif // SHELFCOMPARTMENT_H
