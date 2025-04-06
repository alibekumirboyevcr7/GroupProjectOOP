#ifndef STORE_H
#define STORE_H

#include <string>
#include <vector>

class Store {
private:
    int id;
    std::string name;
    std::string location;
    float rating;
    std::vector<int> products; // Stores product IDs

public:
    Store(int id, std::string name, std::string location, float rating);
    void addProduct(int productId);
    void removeProduct(int productId);
    void displayStoreInfo() const;
};

#endif
