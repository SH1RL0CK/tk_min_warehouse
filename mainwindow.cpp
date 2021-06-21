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
    setUp();
    displayCurrentCompartment();
    displayTemperatureSensorsResults();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUp()
{
    ui->temperatureSensorsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for (unsigned int i = 0; i < warehosueController->getTemperatureSensors().size(); i++)
    {
        ui->temperatureSensorsTable->insertRow(i);
    }
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

void MainWindow::displayTemperatureSensorsResults()
{
    for (unsigned int i = 0; i < warehosueController->getTemperatureSensors().size(); i++)
    {
        TemperatureSensor *sensor = warehosueController->getTemperatureSensors()[i];
        double temperature = 0.0;
        QDateTime time;
        sensor->getMeasurementResult(temperature, time);
        ui->temperatureSensorsTable->setItem(i, 0, new QTableWidgetItem(QString::number(sensor->getId())));
        ui->temperatureSensorsTable->setItem(i, 1, new QTableWidgetItem(time.toString("dd.MM hh:mm:ss")));
        ui->temperatureSensorsTable->setItem(i, 2, new QTableWidgetItem(QString::number(temperature) + "°C"));
    }
     QTimer::singleShot(2000, this, SLOT(displayTemperatureSensorsResults()));
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
