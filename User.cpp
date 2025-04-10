#include "User.h"
#include <iostream>
#include <algorithm>

using namespace std;

User::User(int id, string name, string email, string password, string address, string phone)
    : id(id), name(name), email(email), password(password), address(address), phone(phone) {}

User::~User() {}

void User::addToWishlist(int productId) {
    if (find(wishlist.begin(), wishlist.end(), productId) == wishlist.end()) {
        wishlist.push_back(productId);
    } else {
        cout << "Product already in wishlist.\n";
    }
}

void User::removeFromWishlist(int productId) {
    auto it = remove(wishlist.begin(), wishlist.end(), productId);
    if (it != wishlist.end()) {
        wishlist.erase(it, wishlist.end());
        cout << "Product removed from wishlist.\n";
    } else {
        cout << "Product not found in wishlist.\n";
    }
}

void User::addOrder(int orderId) {
    orderHistory.push_back(orderId);
}

void User::displayUserInfo() const {
    cout << "User: " << name << " (" << email << ")" << endl;
}
