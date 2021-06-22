#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "shelf_compartment.h"

class DatabaseManager
{
private:
    QSqlDatabase database;
    QSqlQuery currentQuery;
    unsigned int numberOfShelves;
    unsigned int numberOfRows;
    unsigned int numberOfCompartments;
    void setUp();
    bool compartmentTableIsIsComplete();
    void fillCompartmentTable();
    ShelfCompartment *readCompartmentFromQuery();
public:
    DatabaseManager(
        unsigned int _numberOfShelves,
        unsigned int _numberOfRows,
        unsigned int _numberOfCompartments
    );
    ShelfCompartment *createCompartmentsList();
};

#endif // DATABASEMANAGER_H
