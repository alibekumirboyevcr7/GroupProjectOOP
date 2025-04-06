#ifndef CART_H
#define CART_H

#include <vector>
#include "Product.h"

class Cart {
private:
    std::vector<Product> items;
    float totalPrice;

public:
    Cart();
    void addItem(const Product& product);
    void removeItem(int productId);
    void displayCart() const;
    void clearCart();  // Added clearCart() for checkout
    float getTotalPrice() const { return totalPrice; }  // Needed for payment
    bool isEmpty() const { return items.empty(); }  // Added isEmpty()
};

#endif
