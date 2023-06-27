#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <QObject>

#include <array>

#include "product.h"




class VendingMachine : public QObject
{

  Q_OBJECT

public:
    VendingMachine();
    std::array<Product, 9> getProducts() const { return m_products; }
    void updateProduct(int id);
private:
    void generateProducts();

signals:
    void updateLabel(int index);
private:
    std::array<Product, 9> m_products;
};

#endif // VENDINGMACHINE_H
