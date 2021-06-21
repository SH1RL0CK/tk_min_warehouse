#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "warehouse_controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    WarehouseController *warehosueController;
    ShelfCompartment *currentCompartment;
    void setUp();
    unsigned int getCurrentCompartmentId();
    void displayCurrentCompartment();

private slots:
    void on_shelfNumberInput_valueChanged(int newShelfNumber);
    void on_rowNumberInput_valueChanged(int newRowNumber);
    void on_compartmentNumberInput_valueChanged(int newCompartmentNumber);
    void on_storeOrEditPalettButton_clicked();
    void on_removePalettButton_clicked();
    void on_displayWholeWarehouseButton_clicked();
    void displayTemperatureSensorsResults();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
