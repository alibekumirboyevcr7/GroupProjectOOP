#include "Store.h"
#include <iostream>
#include <algorithm> // Include for std::remove

Store::Store(int id, std::string name, std::string location, float rating)
    : id(id), name(name), location(location), rating(rating) {}

void Store::addProduct(int productId) {
    products.push_back(productId);
}

void Store::removeProduct(int productId) {
    auto it = std::remove(products.begin(), products.end(), productId);
    products.erase(it, products.end()); // Corrected: Use the returned iterator
}

void Store::displayStoreInfo() const {
    std::cout << "Store: " << name << " | Location: " << location << " | Rating: " << rating << std::endl;
}
