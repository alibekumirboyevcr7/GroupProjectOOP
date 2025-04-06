#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
protected:
    int id;
    std::string name;
    std::string email;
    std::string password;
    std::string address;
    std::string phone;
    std::vector<int> wishlist; // Stores product IDs
    std::vector<int> orderHistory; // Stores order IDs

public:
    User(int id, std::string name, std::string email, std::string password, std::string address, std::string phone);
    virtual ~User();

    void addToWishlist(int productId);
    void removeFromWishlist(int productId);
    void addOrder(int orderId);
    std::string getEmail() const { return email; }
    std::string getPassword() const { return password; }
    std::string getName() const { return name; }

    void displayUserInfo() const;
};

#endif
