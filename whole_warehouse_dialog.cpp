#include "whole_warehouse_dialog.h"
#include "ui_whole_warehouse_dialog.h"

WholeWarehouseDialog::WholeWarehouseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WholeWarehouseDialog)
{
    ui->setupUi(this);
}

WholeWarehouseDialog::~WholeWarehouseDialog()
{
    delete ui;
}
