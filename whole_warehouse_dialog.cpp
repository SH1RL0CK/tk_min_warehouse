#include "whole_warehouse_dialog.h"
#include "ui_whole_warehouse_dialog.h"

WholeWarehouseDialog::WholeWarehouseDialog(WarehouseController *_warehouseController, QWidget *parent) :
    QDialog(parent)
    , ui(new Ui::WholeWarehouseDialog)
    , warehouseController(_warehouseController)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->warehouseTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    displayWholeWarehouse();
}

WholeWarehouseDialog::~WholeWarehouseDialog()
{
    delete ui;
}

void WholeWarehouseDialog::displayWholeWarehouse()
{
    ShelfCompartment *tmpCompartment = warehouseController->getFirstCompartment();
    int rowCount = 0;
    while(tmpCompartment != nullptr)
    {
        ui->warehouseTable->insertRow(rowCount);
        displayCompartment(rowCount, tmpCompartment);
        tmpCompartment = tmpCompartment->getNextCompartment();
        rowCount++;
    }
}

void WholeWarehouseDialog::displayCompartment(int rowCount, ShelfCompartment *compartment)
{
    QTableWidget *warehouseTable = ui->warehouseTable;
    unsigned int shelfNumber = 0, rowNumber = 0, compartmentNumber = 0;
    compartment->extractLocationFromId(shelfNumber, rowNumber, compartmentNumber);
    warehouseTable->setItem(rowCount, 0, new QTableWidgetItem(QString::number(shelfNumber)));
    warehouseTable->setItem(rowCount, 1, new QTableWidgetItem(QString::number(rowNumber)));
    warehouseTable->setItem(rowCount, 2, new QTableWidgetItem(QString::number(compartmentNumber)));
    bool containsPalett = compartment->getPalett() != nullptr;
    warehouseTable->setItem(rowCount, 3, new QTableWidgetItem(containsPalett ? "Ja" : "Nein"));
    warehouseTable->setItem(rowCount, 4, new QTableWidgetItem(containsPalett ? compartment->getPalett()->productName : "-"));
    warehouseTable->setItem(rowCount, 5, new QTableWidgetItem(containsPalett ? QString::number(compartment->getPalett()->numberOfProducts) : "-"));
}
