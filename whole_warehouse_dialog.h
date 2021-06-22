#ifndef WHOLE_WAREHOUSE_DIALOG_H
#define WHOLE_WAREHOUSE_DIALOG_H

#include <QDialog>
#include "warehouse_controller.h"

namespace Ui {
class WholeWarehouseDialog;
}

/**
 * @brief Dialog, der den Inhalt des gesamten Lagers anzeigt
 */
class WholeWarehouseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WholeWarehouseDialog(WarehouseController *_warehouseController, QWidget *parent = nullptr);
    ~WholeWarehouseDialog();

private:
    Ui::WholeWarehouseDialog *ui;
    WarehouseController *warehouseController;
    /**
     * @brief Anzeigen des Gesamten Lager in einer Tabelle
     */
    void displayWholeWarehouse();
    /**
     * @brief Zeigt den Inhalt eines einzelnen Regalfachs in einer Tabellenreihe an
     * @param rowCount  Nummer der Reihe
     * @param compartment  Das Regalfach
     */
    void displayCompartment(int rowCount, ShelfCompartment *compartment);
};

#endif // WHOLE_WAREHOUSE_DIALOG_H
