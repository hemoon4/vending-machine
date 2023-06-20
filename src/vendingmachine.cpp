#include "vendingmachine.h"

#include <QRandomGenerator>

#include <random>

VendingMachine::VendingMachine()
    : products(9)
{
    generateProducts();
}

Product& VendingMachine::getProductByIndex(int index)
{
    if(index > -1 && index < 9)
    {
        return products[index];
    }
}

bool VendingMachine::updateProduct(int id)
{
    for(int i = 0; i < products.size(); ++i)
    {
        Product& product = products[i];
        if(product.getID() == id)
        {
            if(product.getCount() != 0)
            {
                product.setCount(product.getCount() - 1);
                emit updateLabel(i);
                return true;
            }else
            {
                return false;
            }
        }
    }
    return false;
}

void VendingMachine::generateProducts()
{
    std::uniform_real_distribution<float> distFloat(0.99, 9.99);
    std::uniform_int_distribution<int> distInt(0, 14);

    for(int i = 0; i < products.size(); ++i)
    {
        int count = distInt(*QRandomGenerator::global());
        float price = distFloat(*QRandomGenerator::global());
        products[i] = Product(i+1, count, price);
    }
}
