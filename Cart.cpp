#include "Cart.h"
#include <iostream>

Cart::Cart() : totalPrice(0) {}

void Cart::addItem(const Product& product) {
    items.push_back(product);
    totalPrice += product.getPrice();
}

void Cart::removeItem(int productId) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getId() == productId) {
            totalPrice -= it->getPrice();
            items.erase(it);
            break;
        }
    }
}

void Cart::displayCart() const {
    if (items.empty()) {
        std::cout << "Cart is empty!\n";
        return;
    }

    std::cout << "Cart Contents:\n";
    for (const auto& item : items) {
        item.displayProductInfo();
    }
    std::cout << "Total Price: $" << totalPrice << std::endl;
}

void Cart::clearCart() {
    items.clear();
    totalPrice = 0;
}
