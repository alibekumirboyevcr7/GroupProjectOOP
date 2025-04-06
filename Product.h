#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    int id;
    std::string name;
    std::string description;
    float price;
    int stock;

public:
    Product(int id, std::string name, std::string description, float price, int stock);

    // Getter methods (Add these)
    int getId() const { return id; }
    float getPrice() const { return price; }

    void updateStock(int quantity);
    void displayProductInfo() const;
};

#endif
