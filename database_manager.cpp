#include "database_manager.h"

DatabaseManager::DatabaseManager(
    unsigned int _numberOfShelves,
    unsigned int _numberOfRows,
    unsigned int _numberOfCompartments
)
    : database(QSqlDatabase::addDatabase("QSQLITE"))
    , numberOfShelves(_numberOfShelves)
    , numberOfRows(_numberOfRows)
    , numberOfCompartments(_numberOfCompartments)
{
    setUp();

}

void DatabaseManager::setUp()
{
    database.setDatabaseName("tk_min_warehouse.db");
    if(database.open())
    {
        if(!currentQuery.exec(
                    "CREATE TABLE IF NOT EXISTS compartment ("
                        "compartment_id INT PRIMARY KEY NOT NULL, "
                        "contains_palett BOOLEAN NOT NULL, "
                        "productname VARCHAR, "
                        "number_of_products INT"
                    ");"
                  )
        )
           qWarning() << "Es gab ein Problem bei dem Erstellen der Tabelle für die Regalfächer!";
        if(!compartmentTableIsIsComplete())
            fillCompartmentTable();
    }
    else
        qWarning() << "Es gibt ein Problem bei dem Zugriff auf die Datenbank!";
}

bool DatabaseManager::compartmentTableIsIsComplete()
{

    if(currentQuery.exec("SELECT COUNT(*) FROM compartment;"))
    {
        if(currentQuery.first())
            if(currentQuery.value(0).toInt() != numberOfShelves * numberOfRows * numberOfCompartments)
                return false;
    }
    else
        qWarning() << "Es gab ein Problem bei dem Lesen der Regalfächer von der Datenbank!";
    return true;

}

void DatabaseManager::fillCompartmentTable()
{
    currentQuery.exec("DELETE FROM compartment;");
    QString queryCommand = "INSERT INTO compartment (compartment_id, contains_palett) VALUES ";
    for (unsigned int i = 1; i <= numberOfShelves; i++)
    {
        for (unsigned int j = 1; j <= numberOfRows; j++)
        {
            for (unsigned int k = 1; k <= numberOfCompartments; k++)
            {
                unsigned int compartmentId = ShelfCompartment::createId(i, j, k);
                queryCommand += QString("(" + QString::number(compartmentId) + ", 0)");
                if(i == numberOfShelves && j == numberOfRows && k == numberOfCompartments)
                    queryCommand += QString(";");
                else
                    queryCommand += QString(", ");
            }
        }
    }
    if(!currentQuery.exec(queryCommand))
        qWarning() << "Es trat ein Fehler beim Eintragen eines Regalfachs in die Tabelle auf!";
}

ShelfCompartment *DatabaseManager::readCompartmentFromQuery()
{
    ShelfCompartment *newCompartment = new ShelfCompartment(currentQuery.value(0).toInt());
    if(currentQuery.value(1).toBool())
        newCompartment->setPalett(new Palett(currentQuery.value(2).toString(), currentQuery.value(3).toInt()));
    return newCompartment;
}

ShelfCompartment *DatabaseManager::createCompartmentsList()
{
    ShelfCompartment *firstCompartment = nullptr, *tmpCompartment = nullptr;
    if(!currentQuery.exec("SELECT * FROM compartment ORDER BY compartment_id;"))
        qWarning() << "Es trat ein Fehler beim Auslesen der Regalfächer aus der Datenbank auf!";
    if(currentQuery.next())
    {
        firstCompartment = readCompartmentFromQuery();
        tmpCompartment = firstCompartment;
        while(currentQuery.next())
        {
            tmpCompartment->setNextCompartment(readCompartmentFromQuery());
            tmpCompartment = tmpCompartment->getNextCompartment();
        }
    }
    return firstCompartment;
}


