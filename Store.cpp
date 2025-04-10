#include "Store.h"
#include <iostream>
#include <algorithm>

using namespace std;

Store::Store(int id, string name, string location, float rating)
    : id(id), name(name), location(location), rating(rating) {}

void Store::addProduct(int productId) {
    if (find(products.begin(), products.end(), productId) != products.end()) {
        cout << "Product ID " << productId << " already exists in store.\n";
        return;
    }
    products.push_back(productId);
    cout << "Product ID " << productId << " added to store.\n";
}

void Store::removeProduct(int productId) {
    auto it = remove(products.begin(), products.end(), productId);
    if (it != products.end()) {
        products.erase(it, products.end());
        cout << "Product ID " << productId << " removed from store.\n";
    } else {
        cout << "Product ID " << productId << " not found in store.\n";
    }
}

void Store::displayProducts() const {
    cout << "Products in store: ";
    if (products.empty()) {
        cout << "No products.\n";
        return;
    }
    for (int id : products) {
        cout << id << " ";
    }
    cout << endl;
}

void Store::displayStoreInfo() const {
    cout << "Store: " << name << " | Location: " << location << " | Rating: " << rating << endl;
}