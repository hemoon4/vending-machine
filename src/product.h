#ifndef PRODUCT_H
#define PRODUCT_H


class Product
{
public:
    Product();
    Product(int id, int count, float price);

    int getID() const { return m_id; }
    int getCount() const { return m_count; }
    float getPrice() const { return m_price; }

    void setCount(int count) { m_count = count; }
    void setPrice(float price) { m_price = price; }

private:
    int m_id;
    int m_count;
    float m_price;
};

#endif // PRODUCT_H
