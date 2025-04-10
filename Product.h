#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product {
private:
    int id;
    string name;
    string description;
    float price;
    int stock;

public:
    Product(int id, string name, string description, float price, int stock);

    int getId() const { return id; }
    float getPrice() const { return price; }
    string getName() const { return name; }
    int getStock() const { return stock; }
    bool isInStock() const { return stock > 0; }

    void updateStock(int quantity);
    void displayProductInfo() const;
};

#endif
