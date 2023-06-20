#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QLabel>

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
    void on_pushButton_clicked();
    void updateProductLabel(int index);

private:
    void displayProducts();

private:

    Ui::MainWindow *ui;
    VendingMachine vendingMachine;
    QVector<QLabel*> labels;
};
#endif // MAINWINDOW_H
