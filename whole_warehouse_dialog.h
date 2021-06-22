#ifndef WHOLE_WAREHOUSE_DIALOG_H
#define WHOLE_WAREHOUSE_DIALOG_H

#include <QDialog>
#include "warehouse_controller.h"

namespace Ui {
class WholeWarehouseDialog;
}

class WholeWarehouseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WholeWarehouseDialog(WarehouseController *_warehouseController, QWidget *parent = nullptr);
    ~WholeWarehouseDialog();

private:
    Ui::WholeWarehouseDialog *ui;
    WarehouseController *warehouseController;
    void displayWholeWarehouse();
    void displayCompartment(int rowCount, ShelfCompartment *compartment);
};

#endif // WHOLE_WAREHOUSE_DIALOG_H
