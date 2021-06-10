#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , warehosueController(new WarehouseController())
{
    ui->setupUi(this);
    setUp();
    warehosueController->storePalettInCompartment(10101, "Pizza Salami", 12);
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
