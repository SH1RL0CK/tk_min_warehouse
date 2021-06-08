#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_shelfNumberInput_valueChanged(int newShelfNumber)
{

}

void MainWindow::on_rowNumberInput_valueChanged(int newRowNumber)
{

}

void MainWindow::on_compartmentNumberInput_valueChanged(int newCompartmentNumber)
{

}
