#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <vector>
#include <string>

using namespace std;

class Admin : public User {
private:
    vector<string> permissions;

public:
    Admin(int id, string name, string email, string password, string address, string phone);
    void addPermission(string permission);
    void removePermission(string permission);
    void displayPermissions() const;

    string getEmail() const { return email; }
    string getPassword() const { return password; }
    string getName() const { return name; }
};

#endif
