#include "Product.h"
#include <iostream>

Product::Product(int id, std::string name, std::string description, float price, int stock)
    : id(id), name(name), description(description), price(price), stock(stock) {}

void Product::updateStock(int quantity) {
    stock += quantity;
}

void Product::displayProductInfo() const {
    std::cout << "Product: " << name << " | ID: " << id << " | Price: $" << price << " | Stock: " << stock << std::endl;
}
