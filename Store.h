#ifndef STORE_H
#define STORE_H

#include <string>
#include <vector>

using namespace std;

class Store {
private:
    int id;
    string name;
    string location;
    float rating;
    vector<int> products;

public:
    Store(int id, string name, string location, float rating);
    void addProduct(int productId);
    void removeProduct(int productId);
    void displayStoreInfo() const;
    void displayProducts() const;
};

#endif
