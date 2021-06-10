#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , warehosueController(new WarehouseController())
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
    ShelfCompartment *currentCompartment = warehosueController->searchForCompartment(currentCompartmentId);
    Palett *palett = currentCompartment->getPalett();
    if(currentCompartment != nullptr)
    {
        if(palett == nullptr)
        {
            ui->compartmentContainsPalettOutput->setText("Nein");
            ui->productNameInput->setCurrentIndex(-1);
            ui->numberOfProductsInput->setValue(1);
        }
        else
        {
            ui->compartmentContainsPalettOutput->setText("Ja");
            ui->productNameInput->setCurrentText(palett->productName);
            ui->numberOfProductsInput->setValue(palett->numberOfProducts);
        }
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
