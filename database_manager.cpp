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
        QSqlQuery createTableQuery;
        if(!createTableQuery.exec(
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

    QSqlQuery numberOfComaprtmentsQuery;
    if(numberOfComaprtmentsQuery.exec("SELECT COUNT(*) FROM compartment;"))
    {
        if(numberOfComaprtmentsQuery.first())
            if(numberOfComaprtmentsQuery.value(0).toInt() != numberOfShelves * numberOfRows * numberOfCompartments)
                return false;
    }
    else
        qWarning() << "Es gab ein Problem bei dem Lesen der Regalfächer von der Datenbank!";
    return true;

}

void DatabaseManager::fillCompartmentTable()
{
    QSqlQuery clearTableQUery;
    clearTableQUery.exec("DELETE FROM compartment;");
    QSqlQuery insertQuery;
    QString query = "INSERT INTO compartment (compartment_id, contains_palett) VALUES ";
    for (unsigned int i = 1; i <= numberOfShelves; i++)
    {
        for (unsigned int j = 1; j <= numberOfRows; j++)
        {
            for (unsigned int k = 1; k <= numberOfCompartments; k++)
            {
                unsigned int compartmentId = ShelfCompartment::createId(i, j, k);
                query += QString("(" + QString::number(compartmentId) + ", 0)");
                if(i == numberOfShelves && j == numberOfRows && k == numberOfCompartments)
                    query += QString(";");
                else
                    query += QString(", ");
            }
        }
    }
    if(!insertQuery.exec(query))
       qWarning() << "Es trat ein Fehler beim Eintragen eines Regalfachs in die Tabelle auf!";
    qWarning() << insertQuery.lastError().text();
}

