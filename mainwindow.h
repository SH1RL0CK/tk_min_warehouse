#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_shelfNumberInput_valueChanged(int newShelfNumber);
    void on_rowNumberInput_valueChanged(int newRowNumber);
    void on_compartmentNumberInput_valueChanged(int newCompartmentNumber);

private:
    Ui::MainWindow *ui;
    void displayCurrentCompartment();
};
#endif // MAINWINDOW_H
