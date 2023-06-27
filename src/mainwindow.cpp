#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
#include <QLabel>
#include <QLayout>
#include <QIntValidator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_vendingMachine()
    , m_labels()
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(1, 9));
    displayProducts();

    connect(&m_vendingMachine, &VendingMachine::updateLabel, this, &MainWindow::updateProductLabel);

}


void MainWindow::displayProducts()
{
    std::array<Product, 9> products = m_vendingMachine.getProducts();
    const QString productInfoTemplate = "%1 \n"
                                         "Price: %2 \n"
                                         "Quantity: %3";
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            const Product product = products[3*i + j];
            const QString productInfoText = productInfoTemplate.arg(product.getID()).arg(product.getPrice(), 0, 'g', 3).arg(product.getCount());
            QLabel* productLabel = new QLabel(productInfoText);
            m_labels[3*i + j] = productLabel;
            ui->gridLayout->addWidget(productLabel, i, j);
        }
    }
}



void MainWindow::updateProductLabel(int index)
{
    Product product = m_vendingMachine.getProducts()[index];
    const QString text = "%1 \n"
                         "Price: %2 \n"
                         "Quantity: %3";
    const QString formattedText = text.arg(product.getID()).arg(product.getPrice(), 0, 'g', 3).arg(product.getCount());
    m_labels[index]->setText(formattedText);
}

void MainWindow::on_pushButton_clicked()
{
    int id = ui->lineEdit->text().toInt();
    m_vendingMachine.updateProduct(id);

}

MainWindow::~MainWindow()
{
    delete ui;
}

