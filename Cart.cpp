#include "Cart.h"
#include <iostream>
#include <iomanip>

using namespace std;

Cart::Cart() : totalPrice(0) {}

void Cart::addItem(const Product& product) {
    if (!product.isInStock()) {
        cout << "Cannot add " << product.getName() << " - out of stock.\n";
        return;
    }
    items.push_back(product);
    totalPrice += product.getPrice();
}

bool Cart::removeItem(int productId) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getId() == productId) {
            totalPrice -= it->getPrice();
            items.erase(it);
            cout << "Item removed from cart.\n";
            return true;
        }
    }
    cout << "Item not found in cart.\n";
    return false;
}

void Cart::displayCart() const {
    if (items.empty()) {
        cout << "Cart is empty!\n";
        return;
    }

    cout << "Cart Contents:\n";
    for (const auto& item : items) {
        item.displayProductInfo();
    }
    cout << fixed << setprecision(2);
    cout << "Total Price: $" << totalPrice << endl;
}

void Cart::clearCart() {
    items.clear();
    totalPrice = 0;
}
