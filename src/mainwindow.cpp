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
    displayProducts();

    ui->displayLcdNumber->display("");
    std::array<QPushButton*, 10> buttons{ui->btn0, ui->btn1, ui->btn2, ui->btn3, ui->btn4, ui->btn5, ui->btn6, ui->btn7, ui->btn8, ui->btn9};

    //when vending machine found product and product is available, update specific label
    connect(&m_vendingMachine, &VendingMachine::updateLabel, this, &MainWindow::updateProductLabel);

    //getting some product of specific id
    connect(ui->actionButton, SIGNAL(clicked()), this, SLOT(actionButtonClicked()));
    for(int i = 0; i < buttons.size(); ++i)
    {
        connect(buttons[i], SIGNAL(clicked()), this, SLOT(numberActionClicked()));
    }

    //clear LCD Screen
    connect(ui->btnClear, SIGNAL(clicked()), this, SLOT(clearLCDScreen()));

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
            ui->vendingMachineLayout->addWidget(productLabel, i, j);
        }
    }
}

void MainWindow::actionButtonClicked()
{
    int id = ui->displayLcdNumber->value();
    m_vendingMachine.updateProduct(id);

}

void MainWindow::numberActionClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if(button){
        int val = ui->displayLcdNumber->value();
        QString text = val == 0 ? button->text() : QString::number(val).append(button->text());
        ui->displayLcdNumber->display(text);
    }
}

void MainWindow::clearLCDScreen()
{
    ui->displayLcdNumber->display("");
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

MainWindow::~MainWindow()
{
    delete ui;
}

