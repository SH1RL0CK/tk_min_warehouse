#ifndef WHOLE_WAREHOUSE_DIALOG_H
#define WHOLE_WAREHOUSE_DIALOG_H

#include <QDialog>

namespace Ui {
class WholeWarehouseDialog;
}

class WholeWarehouseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WholeWarehouseDialog(QWidget *parent = nullptr);
    ~WholeWarehouseDialog();

private:
    Ui::WholeWarehouseDialog *ui;
};

#endif // WHOLE_WAREHOUSE_DIALOG_H
