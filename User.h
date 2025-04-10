#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using namespace std;

class User {
protected:
    int id;
    string name;
    string email;
    string password;
    string address;
    string phone;
    vector<int> wishlist;
    vector<int> orderHistory;

public:
    User(int id, string name, string email, string password, string address, string phone);
    virtual ~User();

    void addToWishlist(int productId);
    void removeFromWishlist(int productId);
    void addOrder(int orderId);
    string getEmail() const { return email; }
    string getPassword() const { return password; }
    string getName() const { return name; }

    void displayUserInfo() const;
};

#endif
