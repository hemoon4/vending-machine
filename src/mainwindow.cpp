#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
#include <QLabel>
#include <QLayout>
#include <QIntValidator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , vendingMachine()
    , labels(9)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(1, 9));
    displayProducts();

    connect(&vendingMachine, &VendingMachine::updateLabel, this, &MainWindow::updateProductLabel);

}


void MainWindow::displayProducts()
{
    for(int i = 1, rows = 0, cols = 0; i <= 9; ++i, ++cols)
    {
        Product product = vendingMachine.getProductByIndex(i-1);
        const QString text = "%1 \n"
                             "Price: %2 \n"
                             "Quantity: %3";
        const QString formattedText = text.arg(product.getID()).arg(product.getPrice(), 0, 'g', 3).arg(product.getCount());
        QLabel* label = new QLabel();
        labels[i-1] = label;
        label->setText(formattedText);
        ui->gridLayout->addWidget(label, rows, cols);

        if(i % 3 == 0)
        {
            ++rows;
            cols = -1;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateProductLabel(int index)
{
    Product product = vendingMachine.getProductByIndex(index);
    const QString text = "%1 \n"
                         "Price: %2 \n"
                         "Quantity: %3";
    const QString formattedText = text.arg(product.getID()).arg(product.getPrice(), 0, 'g', 3).arg(product.getCount());
    labels[index]->setText(formattedText);
}

void MainWindow::on_pushButton_clicked()
{
    int id = ui->lineEdit->text().toInt();
    bool success = vendingMachine.updateProduct(id);


}

