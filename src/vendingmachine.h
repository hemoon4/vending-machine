#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <QLIst>
#include <QObject>

#include "product.h"



class VendingMachine : public QObject
{

  Q_OBJECT

public:
    VendingMachine();
    Product& getProductByIndex(int index);
    bool updateProduct(int id);
private:
    void generateProducts();

signals:
    void updateLabel(int index);
private:
    QList<Product> products;
};

#endif // VENDINGMACHINE_H
