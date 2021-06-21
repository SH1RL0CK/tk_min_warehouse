#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "whole_warehouse_dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , warehosueController(new WarehouseController())
    , currentCompartment(nullptr)
{
    ui->setupUi(this);
    displayCurrentCompartment();
}

MainWindow::~MainWindow()
{
    delete ui;
}

unsigned int MainWindow::getCurrentCompartmentId()
{
    unsigned int shelfNumber = ui->shelfNumberInput->value();
    unsigned int rowNumber = ui->rowNumberInput->value();
    unsigned int compartmentNumber = ui->compartmentNumberInput->value();
    return ShelfCompartment::createId(shelfNumber, rowNumber, compartmentNumber);
}

void MainWindow::displayCurrentCompartment()
{
    unsigned int currentCompartmentId = getCurrentCompartmentId();
    currentCompartment = warehosueController->searchForCompartment(currentCompartmentId);
    Palett *palett = currentCompartment->getPalett();
    if(currentCompartment == nullptr)
    {
        return;
    }
    if(palett == nullptr)
    {
        ui->compartmentContainsPalettOutput->setText("Nein");
        ui->productNameInput->setCurrentIndex(0);
        ui->numberOfProductsInput->setValue(1);
        ui->storeOrEditPalettButton->setText("Palette einlagern");
        ui->removePalettButton->hide();
    }
    else
    {
        ui->compartmentContainsPalettOutput->setText("Ja");
        ui->productNameInput->setCurrentText(palett->productName);
        ui->numberOfProductsInput->setValue(palett->numberOfProducts);
        ui->storeOrEditPalettButton->setText("Änderungen speichern");
        ui->removePalettButton->show();
    }
}

void MainWindow::on_shelfNumberInput_valueChanged(int newShelfNumber)
{
    displayCurrentCompartment();
}

void MainWindow::on_rowNumberInput_valueChanged(int newRowNumber)
{
    displayCurrentCompartment();
}

void MainWindow::on_compartmentNumberInput_valueChanged(int newCompartmentNumber)
{
    displayCurrentCompartment();
}

void MainWindow::on_storeOrEditPalettButton_clicked()
{
    if(currentCompartment == nullptr)
    {
        return;
    }
    int currentCompartmentId = currentCompartment->getId();
    QString productName = ui->productNameInput->currentText();
    int numberOfProducts = ui->numberOfProductsInput->value();
    if(currentCompartment->getPalett() == nullptr){
        warehosueController->storePalettInCompartment(currentCompartmentId, productName, numberOfProducts);
    }
    else
    {
        warehosueController->editPalettInCompartment(currentCompartmentId, productName, numberOfProducts);
    }
    displayCurrentCompartment();
}

void MainWindow::on_removePalettButton_clicked()
{
    if(currentCompartment == nullptr)
    {
        return;
    }
    warehosueController->removePalettFromCompartment(currentCompartment->getId());
    displayCurrentCompartment();
}

void MainWindow::on_displayWholeWarehouseButton_clicked()
{
    WholeWarehouseDialog wholeWarehouseDialog(warehosueController);
    wholeWarehouseDialog.setModal(true);
    wholeWarehouseDialog.setWindowTitle("Gesamtes Lager anzeigen");
    wholeWarehouseDialog.exec();
}
