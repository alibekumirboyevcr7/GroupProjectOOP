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
    bool removeItem(int productId);
    void displayCart() const;
    int getItemCount() const { return items.size(); }
    void clearCart();
    float getTotalPrice() const { return totalPrice; }
    bool isEmpty() const { return items.empty(); }
};

#endif
