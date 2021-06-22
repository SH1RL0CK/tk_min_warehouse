#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "warehouse_controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Hauptfenster, in der die Regalfächer verwaltet werden und die Temperatursenoren
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    /**
     * @brief Verwaltung der verketten Liste
     */
    WarehouseController *warehosueController;
    /**
     * @brief Regalfach welches aktuell verwaltet wird
     */
    ShelfCompartment *currentCompartment;
    /**
     * @brief Dient zur Darstellung des virtuellen Lagerhauses
     */
    QGraphicsScene *virtualWarehouseScene;
    QGraphicsRectItem *currentCompartmentRect;
    /**
     * @brief Wichtige Vorbereitungen für das Anzeigen des Mainwindows
     */
    void setUp();
    /**
     * @brief Zeichnet das virtuelle Lagerhaus in einer QGraphicsView
     */
    void drawVirtualWarehouse();
    /**
     * @brief Ermittelt die Id des aktuell angezigten Regalfachs
     * @return Die ermittelte Id
     */
    unsigned int getCurrentCompartmentId();
    /**
     * @brief Zeigt den Inhalt des aktuell ausgewählten Regalfachs
     */
    void displayCurrentCompartment();
    /**
     * @brief Makiert wo im virtuellen Lagerhaus sich das Regalfach befindet
     */
    void displayLocationOfCurrentCompartment();

private slots:
    /**
     * @brief Spinbox-Inputfeld für die Regalreihennummer wurde geändert
     * @param Neue Regalreihennummer
     */
    void on_shelfNumberInput_valueChanged(int newShelfNumber);
    /**
     * @brief Spinbox-Inputfeld für die Regalbodennummer wurde geändert
     * @param Neue Regalbodennummer
     */
    void on_rowNumberInput_valueChanged(int newRowNumber);
    /**
     * @brief Spinbox-Inputfeld für die Regalfachnummer wurde geändert
     * @param Neue Regalfachnummer
     */
    void on_compartmentNumberInput_valueChanged(int newCompartmentNumber);
    /**
     * @brief Knopf zum Einlagern oder Bearbeiten einer Palette wurde gedrückt
     */
    void on_storeOrEditPalettButton_clicked();
    /**
     * @brief Knopf zum Auslagern einer Palette wurde gedrückt
     */
    void on_removePalettButton_clicked();
    /**
     * @brief Knopf zum Anzeigen des gesmaten Lagers wurde gedrückt
     */
    void on_displayWholeWarehouseButton_clicked();
    /**
     * @brief Die Ergebnisse der Temperatursensoren-Messungen in einer Tabelle darstellen
     */
    void displayTemperatureSensorsResults();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
