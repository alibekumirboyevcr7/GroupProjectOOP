#include "User.h"
#include <iostream>
#include <algorithm> // Include for std::remove

User::User(int id, std::string name, std::string email, std::string password, std::string address, std::string phone)
    : id(id), name(name), email(email), password(password), address(address), phone(phone) {}

User::~User() {}

void User::addToWishlist(int productId) {
    wishlist.push_back(productId);
}

void User::removeFromWishlist(int productId) {
    auto it = std::remove(wishlist.begin(), wishlist.end(), productId);
    wishlist.erase(it, wishlist.end()); // Corrected: Use the returned iterator
}

void User::addOrder(int orderId) {
    orderHistory.push_back(orderId);
}

void User::displayUserInfo() const {
    std::cout << "User: " << name << " (" << email << ")" << std::endl;
}
