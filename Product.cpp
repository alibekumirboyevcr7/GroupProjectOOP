#include "Product.h"
#include <iostream>

using namespace std;

Product::Product(int id, string name, string description, float price, int stock)
    : id(id), name(name), description(description), price(price), stock(stock) {}

void Product::updateStock(int quantity) {
    if (stock + quantity < 0) {
        cout << "Error: Not enough stock to remove " << -quantity << " items.\n";
    } else {
        stock += quantity;
    }
}

void Product::displayProductInfo() const {
    cout << "Product: " << name << " | ID: " << id << " | Price: $" << price << " | Stock: " << stock << endl;
}
