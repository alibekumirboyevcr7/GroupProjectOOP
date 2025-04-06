#include <iostream>
#include <vector>
#include "User.h"
#include "Admin.h"
#include "Store.h"
#include "Product.h"
#include "Cart.h"
#include "Payment.h"

void displayUserMenu() {
    std::cout << "\n--- User Menu ---\n";
    std::cout << "1. Add Product to Cart\n";
    std::cout << "2. View Cart\n";
    std::cout << "3. Checkout & Pay\n";
    std::cout << "4. Logout\n";
    std::cout << "Choose an option: ";
}

void displayAdminMenu() {
    std::cout << "\n--- Admin Menu ---\n";
    std::cout << "1. View Users\n";
    std::cout << "2. Add Product to Store\n";
    std::cout << "3. Remove Product from Store\n";
    std::cout << "4. View Payments\n";
    std::cout << "5. Logout\n";
    std::cout << "Choose an option: ";
}

int main() {
    std::vector<User> users;
    std::vector<Product> products;
    Cart cart;

    // Predefined admin account
    Admin admin(1, "SuperAdmin", "admin@example.com", "adminpass", "HQ", "999-9999");

    // Sample products
    products.push_back(Product(201, "Laptop", "High-performance laptop", 999.99, 10));
    products.push_back(Product(202, "Smartphone", "Latest model smartphone", 599.99, 20));

    int choice;
    while (true) {
        std::cout << "\n--- Welcome to Shopping App ---\n";
        std::cout << "1. Register as User\n";
        std::cout << "2. Sign in as User\n";
        std::cout << "3. Sign in as Admin\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1) { // Register User
            std::string name, email, password, address, phone;
            std::cout << "Enter Name: "; std::cin >> name;
            std::cout << "Enter Email: "; std::cin >> email;
            std::cout << "Enter Password: "; std::cin >> password;
            std::cout << "Enter Address: "; std::cin >> address;
            std::cout << "Enter Phone: "; std::cin >> phone;

            users.push_back(User(users.size() + 1, name, email, password, address, phone));
            std::cout << "User registered successfully!\n";
        }

        else if (choice == 2) { // Sign in as User
            std::string email, password;
            std::cout << "Enter Email: "; std::cin >> email;
            std::cout << "Enter Password: "; std::cin >> password;

            bool loggedIn = false;
            User* currentUser = nullptr;
            for (auto& user : users) {
                if (user.getEmail() == email && user.getPassword() == password) {
                    std::cout << "Login successful! Welcome, " << user.getName() << ".\n";
                    loggedIn = true;
                    currentUser = &user;
                    break;
                }
            }

            if (!loggedIn) {
                std::cout << "Invalid email or password!\n";
                continue;
            }

            // User Menu
            int userChoice;
            while (true) {
                displayUserMenu();
                std::cin >> userChoice;

                if (userChoice == 1) { // Add Product to Cart
                    std::cout << "\nAvailable Products:\n";
                    for (const auto& product : products) {
                        product.displayProductInfo();
                    }

                    int productId;
                    std::cout << "Enter Product ID to add to cart: ";
                    std::cin >> productId;

                    bool found = false;
                    for (const auto& product : products) {
                        if (product.getId() == productId) {
                            cart.addItem(product);
                            std::cout << "Product added to cart!\n";
                            found = true;
                            break;
                        }
                    }
                    if (!found) std::cout << "Invalid Product ID!\n";
                }

                else if (userChoice == 2) { // View Cart
                    cart.displayCart();
                }

                else if (userChoice == 3) { // Checkout & Pay
                    if (cart.isEmpty()) {
                        std::cout << "Cart is empty! Add items before checkout.\n";
                    } else {
                        std::string paymentMethod;
                        std::cout << "Enter Payment Method (Credit Card/PayPal): ";
                        std::cin >> paymentMethod;

                        Payment payment(301, cart.getTotalPrice(), paymentMethod);
                        payment.processPayment();
                        payment.displayPaymentInfo();

                        if (payment.getStatus() == "Completed") { // Only clear cart if payment was successful
                            cart.clearCart();
                            std::cout << "Purchase successful! Cart is now empty.\n";
                        } else {
                            std::cout << "Purchase failed! Please try again with a different payment method.\n";
                        }
                    }
                }

                else if (userChoice == 4) { // Logout
                    std::cout << "Logging out...\n";
                    break;
                }

                else {
                    std::cout << "Invalid option! Try again.\n";
                }
            }
        }

        else if (choice == 3) { // Sign in as Admin
            std::string email, password;
            std::cout << "Enter Admin Email: "; std::cin >> email;
            std::cout << "Enter Admin Password: "; std::cin >> password;

            if (email == admin.getEmail() && password == admin.getPassword()) {
                std::cout << "Admin login successful! Welcome, " << admin.getName() << ".\n";

                // Admin Menu
                int adminChoice;
                while (true) {
                    displayAdminMenu();
                    std::cin >> adminChoice;

                    if (adminChoice == 1) { // View Users
                        std::cout << "\nRegistered Users:\n";
                        for (const auto& user : users) {
                            user.displayUserInfo();
                        }
                    }

                    else if (adminChoice == 2) { // Add Product
                        int id, stock;
                        std::string name, desc;
                        float price;

                        std::cout << "Enter Product ID: "; std::cin >> id;
                        std::cout << "Enter Product Name: "; std::getline(std::cin, name);
                        std::cout << "Enter Product Description: "; std::getline(std::cin, desc);
                        std::cout << "Enter Product Price: "; std::cin >> price;
                        std::cout << "Enter Stock Quantity: "; std::cin >> stock;

                        products.push_back(Product(id, name, desc, price, stock));
                        std::cout << "Product added successfully!\n";
                    }

                    else if (adminChoice == 3) { // Remove Product
                        int productId;
                        std::cout << "Enter Product ID to remove: ";
                        std::cin >> productId;

                        bool removed = false;
                        for (auto it = products.begin(); it != products.end(); ++it) {
                            if (it->getId() == productId) {
                                products.erase(it);
                                std::cout << "Product removed successfully!\n";
                                removed = true;
                                break;
                            }
                        }
                        if (!removed) std::cout << "Invalid Product ID!\n";
                    }

                    else if (adminChoice == 4) { // View Payments
                        std::cout << "Feature not implemented yet.\n";
                    }

                    else if (adminChoice == 5) { // Logout
                        std::cout << "Logging out...\n";
                        break;
                    }

                    else {
                        std::cout << "Invalid option! Try again.\n";
                    }
                }
            } else {
                std::cout << "Invalid admin credentials!\n";
            }
        }

        else if (choice == 4) { // Exit
            std::cout << "Thank you for using our shopping app!\n";
            break;
        }

        else {
            std::cout << "Invalid option! Try again.\n";
        }
    }

    return 0;
}
