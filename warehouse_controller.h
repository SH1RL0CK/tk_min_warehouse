#ifndef WAREHOUSECONTROLLER_H
#define WAREHOUSECONTROLLER_H

#include <vector>
#include <QString>
#include "shelf_compartment.h"
#include "database_manager.h"
#include "temperature_sensor.h"

/**
 * @brief Diese Klasse ist zur Verwaltung der verketteten Liste und der Temperatursensoren dar
 */
class WarehouseController
{
private:
    unsigned int numberOfShelves;
    unsigned int numberOfRows;
    unsigned int numberOfCompartments;
    unsigned int numberOfTemperatureSensors;
    DatabaseManager *dbManager;
    /**
     * @brief Das erste Element in der verketteten Liste
     */
    ShelfCompartment *firstCompartment;
    /**
     * @brief Die 10 Temperatursensoren werden in einem Vector verwaltet
     */
    std::vector<TemperatureSensor*> temperatureSensors;
    /**
     * @brief Erstellt die 10 Temperatursensoren
     */
    void createTemperatureSensors();
public:
    WarehouseController();
    unsigned int getNumberOfShelves() const;
    unsigned int getNumberOfRows() const;
    unsigned int getNumberOfCompartments() const;
    ShelfCompartment *getFirstCompartment() const;
    std::vector<TemperatureSensor*> getTemperatureSensors() const;
    /**
     * @brief Sucht ein Regalfach in der verketteten Liste
     * @param id  Id nach der gesucht wird
     * @return das gefundene Element oder ein Nullpointer wenn nichts gefunden wurde
     */
    ShelfCompartment *searchForCompartment(unsigned int id);
    /**
     * @brief Einlagern einer Palette in einem Regalfach
     * @param compartmentId  Id des Regalfachs
     * @param productName  Name des Produkts auf der Palette
     * @param numberOfProducts  Anzahl des Produkts auf der Palette
     */
    void storePalettInCompartment(
            unsigned int compartmentId,
            QString productName,
            unsigned int numberOfProducts
     );
    /**
     * @brief Bearbeiten einer Palette in einem Regalfach
     * @param compartmentId  Id des Regalfachs
     * @param newProductName  (neuer) Name des Produkts auf der Palette
     * @param newNumberOfProducts  (neue) Anzahl des Produkts auf der Palette
     */
    void editPalettInCompartment(
            unsigned int compartmentId,
            QString newProductName,
            unsigned int newNumberOfProducts
     );
    /**
     * @brief Palette aus Regalfach auslagern
     * @param compartmentId  Id des Regalfachs
     */
    void removePalettFromCompartment(unsigned int compartmentId);
};

#endif // WAREHOUSECONTROLLER_H
