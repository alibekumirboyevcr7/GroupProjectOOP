#include "Admin.h"
#include <iostream>
#include <algorithm> // Include for std::remove

Admin::Admin(int id, std::string name, std::string email, std::string password, std::string address, std::string phone)
    : User(id, name, email, password, address, phone) {}

void Admin::addPermission(std::string permission) {
    permissions.push_back(permission);
}

void Admin::removePermission(std::string permission) {
    auto it = std::remove(permissions.begin(), permissions.end(), permission);
    permissions.erase(it, permissions.end()); // Corrected: Use the returned iterator
}

void Admin::displayPermissions() const {
    std::cout << "Admin Permissions: ";
    for (const auto& perm : permissions)
        std::cout << perm << ", ";
    std::cout << std::endl;
}
