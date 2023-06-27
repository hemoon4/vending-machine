#include "vendingmachine.h"

#include <QRandomGenerator>
#include <QDebug>

#include <random>

VendingMachine::VendingMachine()
    : m_products()
{
    generateProducts();
}


void VendingMachine::updateProduct(int id)
{
    for(int i = 0; i < m_products.size(); ++i)
    {
        Product& product = m_products[i];
        if(product.getID() == id)
        {
            if(product.getCount() != 0)
            {
                product.setCount(product.getCount() - 1);
                emit updateLabel(i);
            }else
            {
                qDebug() << "Product is empty. ";
                return;
            }
        }
    }
}

void VendingMachine::generateProducts()
{
    std::uniform_real_distribution<float> distFloat(0.99, 9.99);
    std::uniform_int_distribution<int> distInt(0, 14);

    for(int i = 0; i < m_products.size(); ++i)
    {
        int count = distInt(*QRandomGenerator::global());
        float price = distFloat(*QRandomGenerator::global());
        m_products[i] = Product(i+1, count, price);
    }
}
