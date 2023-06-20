#ifndef PRODUCT_H
#define PRODUCT_H


class Product
{


public:
    Product();
    Product(int id, int count, float price);

    int getID() const { return m_ID; }
    int getCount() const { return m_Count; }
    float getPrice() const { return m_Price; }

    void setCount(int count) { m_Count = count; }
    void setPrice(float price) { m_Price = price; }

private:
    int m_ID;
    int m_Count;
    float m_Price;
};

#endif // PRODUCT_H
