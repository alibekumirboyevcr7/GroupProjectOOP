#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User {
private:
    std::vector<std::string> permissions;

public:
    Admin(int id, std::string name, std::string email, std::string password, std::string address, std::string phone);
    void addPermission(std::string permission);
    void removePermission(std::string permission);
    void displayPermissions() const;

    std::string getEmail() const { return email; }
    std::string getPassword() const { return password; }
    std::string getName() const { return name; }

};

#endif
