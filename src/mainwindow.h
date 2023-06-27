#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QLabel>
#include <array>


#include "vendingmachine.h"


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
    void actionButtonClicked();
    void numberActionClicked();
    void clearLCDScreen();
    void updateProductLabel(int index);

private:
    void displayProducts();

private:

    Ui::MainWindow *ui;
    VendingMachine m_vendingMachine;
    std::array<QLabel*, 9> m_labels;
    QLCDNumber* lcd;
};
#endif // MAINWINDOW_H
