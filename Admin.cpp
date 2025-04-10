#include "Admin.h"
#include <iostream>
#include <algorithm>

using namespace std;

Admin::Admin(int id, string name, string email, string password, string address, string phone)
    : User(id, name, email, password, address, phone) {}

void Admin::addPermission(string permission) {
    if (find(permissions.begin(), permissions.end(), permission) == permissions.end()) {
        permissions.push_back(permission);
    } else {
        cout << "Permission already granted.\n";
    }
}

void Admin::removePermission(string permission) {
    auto it = remove(permissions.begin(), permissions.end(), permission);
    if (it != permissions.end()) {
        permissions.erase(it, permissions.end());
        cout << "Permission removed.\n";
    } else {
        cout << "Permission not found.\n";
    }
}

void Admin::displayPermissions() const {
    cout << "Admin Permissions: ";
    for (const auto& perm : permissions)
        cout << perm << ", ";
    cout << endl;
}