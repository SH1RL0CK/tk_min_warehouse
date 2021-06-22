#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "shelf_compartment.h"


/**
 * @brief Diese Klasse ist zur Verwaltung der SQLite Datenbank dar
 */
class DatabaseManager
{
private:
    /**
     * @brief Die Datenbankverbindung
     */
    QSqlDatabase database;
    /**
     * @brief Die aktuelle SQL-Abfrage
     */
    QSqlQuery currentQuery;
    unsigned int numberOfShelves;
    unsigned int numberOfRows;
    unsigned int numberOfCompartments;
    /**
     * @brief Stellt eine Verbindung zur Datenbank her und erstellt ggf. die Tabelle für die Regalfächer
     */
    void setUp();
    /**
     * @brief Überprüft, ob die Tabelle für die Regalfächer Inhalt hat bzw. ob dieser vollständig ist
     * @return Boolean zur Überprüfung
     */
    bool compartmentTableIsIsComplete();
    /**
     * @brief Falls die Tabelle unvollständig oder leer ist, wird sie komplett neu befüllt
     */
    void fillCompartmentTable();
    /**
     * @brief Erstellt ein Regalfach aus dem Ergebnis der SQL-Abfrage
     * @return Das erzugte Regalfach
     */
    ShelfCompartment *readCompartmentFromQuery();
public:
    DatabaseManager(
        unsigned int _numberOfShelves,
        unsigned int _numberOfRows,
        unsigned int _numberOfCompartments
    );
    /**
     * @brief Liefert aus dem Inhalt der Tabelle die verketette Liste für die Regalfächer
     * @return Das erste Element in der verketetten Liste
     */
    ShelfCompartment *createCompartmentsList();
    /**
     * @brief Speichert Änderungen (Einlagern, Bearbeiten und Auslagern einer Palette)
     *        an einem Regalfach in der Datenbank
     * @param compartment  Das Regalfach welches verändert wurde
     */
    void updateCompartment(ShelfCompartment *compartment);
};

#endif // DATABASEMANAGER_H
