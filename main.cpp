#include <iostream>
#include <vector>
#include <limits>
#include "User.h"
#include "Admin.h"
#include "Store.h"
#include "Product.h"
#include "Cart.h"
#include "Payment.h"

using namespace std;

void displayUserMenu() {
    cout << "\n--- User Menu ---\n";
    cout << "1. Add Product to Cart\n";
    cout << "2. View Cart\n";
    cout << "3. Checkout & Pay\n";
    cout << "4. Logout\n";
    cout << "Choose an option: ";
}

void displayAdminMenu() {
    cout << "\n--- Admin Menu ---\n";
    cout << "1. View Users\n";
    cout << "2. Add Product to Store\n";
    cout << "3. Remove Product from Store\n";
    cout << "4. View Payments\n";
    cout << "5. Logout\n";
    cout << "Choose an option: ";
}

int getValidatedInt() {
    int value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a number: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Remove leftover newline
    return value;
}

float getValidatedFloat() {
    float value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a valid price: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

string getValidatedString(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        if (!input.empty()) return input;
        cout << "Input cannot be empty. Please try again.\n";
    }
}

string getPaymentMethod() {
    string method;
    while (true) {
        cout << "Enter Payment Method (Credit Card/PayPal): ";
        getline(cin, method);
        if (method == "Credit Card" || method == "PayPal") return method;
        cout << "Invalid method. Please enter 'Credit Card' or 'PayPal'.\n";
    }
}

int main() {
    vector<User> users;
    vector<Product> products;
    Cart cart;

    Admin admin(1, "SuperAdmin", "admin@example.com", "adminpass", "HQ", "999-9999");

    products.push_back(Product(201, "Laptop", "High-performance laptop", 999.99, 10));
    products.push_back(Product(202, "Smartphone", "Latest model smartphone", 599.99, 20));

    int choice;
    while (true) {
        cout << "\n--- Welcome to Shopping App ---\n";
        cout << "1. Register as User\n";
        cout << "2. Sign in as User\n";
        cout << "3. Sign in as Admin\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        choice = getValidatedInt();

        if (choice == 1) {
            string name = getValidatedString("Enter Name: ");
            string email;

            while (true) {
                email = getValidatedString("Enter Email: ");
                bool exists = false;
                for (const auto& u : users) {
                    if (u.getEmail() == email) {
                        cout << "Email already registered. Try another one.\n";
                        exists = true;
                        break;
                    }
                }
                if (!exists) break;
            }

            string password = getValidatedString("Enter Password: ");
            string address = getValidatedString("Enter Address: ");
            string phone = getValidatedString("Enter Phone: ");

            users.push_back(User(users.size() + 1, name, email, password, address, phone));
            cout << "User registered successfully!\n";
        }
        else if (choice == 2) {
            string email, password;
            cout << "Enter Email: "; getline(cin, email);
            cout << "Enter Password: "; getline(cin, password);

            bool loggedIn = false;
            User* currentUser = nullptr;
            for (auto& user : users) {
                if (user.getEmail() == email && user.getPassword() == password) {
                    cout << "Login successful! Welcome, " << user.getName() << ".\n";
                    loggedIn = true;
                    currentUser = &user;
                    break;
                }
            }

            if (!loggedIn) {
                cout << "Invalid email or password!\n";
                continue;
            }

            int userChoice;
            while (true) {
                displayUserMenu();
                userChoice = getValidatedInt();

                if (userChoice == 1) {
                    cout << "\nAvailable Products:\n";
                    for (const auto& product : products) {
                        product.displayProductInfo();
                    }

                    cout << "Enter Product ID to add to cart: ";
                    int productId = getValidatedInt();

                    bool found = false;
                    for (const auto& product : products) {
                        if (product.getId() == productId) {
                            cart.addItem(product);
                            cout << "Product added to cart!\n";
                            found = true;
                            break;
                        }
                    }
                    if (!found) cout << "Invalid Product ID!\n";
                }

                else if (userChoice == 2) {
                    cart.displayCart();
                }

                else if (userChoice == 3) {
                    if (cart.isEmpty()) {
                        cout << "Cart is empty! Add items before checkout.\n";
                    } else {
                        string paymentMethod = getPaymentMethod();

                        try {
                            Payment payment(301, cart.getTotalPrice(), paymentMethod);
                            payment.processPayment();
                            payment.displayPaymentInfo();

                            if (payment.getStatus() == "Completed") {
                                cart.clearCart();
                                cout << "Purchase successful! Cart is now empty.\n";
                            } else {
                                cout << "Purchase failed! Please try again.\n";
                            }
                        } catch (const std::invalid_argument& e) {
                            cout << "Payment Error: " << e.what() << "\n";
                        }
                    }
                }

                else if (userChoice == 4) {
                    cout << "Logging out...\n";
                    break;
                }

                else {
                    cout << "Invalid option! Try again.\n";
                }
            }
        }

        else if (choice == 3) {
            string email, password;
            cout << "Enter Admin Email: "; getline(cin, email);
            cout << "Enter Admin Password: "; getline(cin, password);

            if (email == admin.getEmail() && password == admin.getPassword()) {
                cout << "Admin login successful! Welcome, " << admin.getName() << ".\n";

                int adminChoice;
                while (true) {
                    displayAdminMenu();
                    adminChoice = getValidatedInt();

                    if (adminChoice == 1) {
                        cout << "\nRegistered Users:\n";
                        for (const auto& user : users) {
                            user.displayUserInfo();
                        }
                    }

                    else if (adminChoice == 2) {
                        int id, stock;
                        float price;
                        string name, desc;

                        cout << "Enter Product ID: ";
                        id = getValidatedInt();
                        cout << "Enter Product Name: ";
                        getline(cin, name);
                        cout << "Enter Product Description: ";
                        getline(cin, desc);
                        cout << "Enter Product Price: ";
                        price = getValidatedFloat();
                        cout << "Enter Stock Quantity: ";
                        stock = getValidatedInt();

                        products.push_back(Product(id, name, desc, price, stock));
                        cout << "Product added successfully!\n";
                    }

                    else if (adminChoice == 3) {
                        cout << "Enter Product ID to remove: ";
                        int productId = getValidatedInt();

                        bool removed = false;
                        for (auto it = products.begin(); it != products.end(); ++it) {
                            if (it->getId() == productId) {
                                products.erase(it);
                                cout << "Product removed successfully!\n";
                                removed = true;
                                break;
                            }
                        }
                        if (!removed) cout << "Invalid Product ID!\n";
                    }

                    else if (adminChoice == 4) {
                        cout << "Feature not implemented yet.\n";
                    }

                    else if (adminChoice == 5) {
                        cout << "Logging out...\n";
                        break;
                    }

                    else {
                        cout << "Invalid option! Try again.\n";
                    }
                }
            } else {
                cout << "Invalid admin credentials!\n";
            }
        }

        else if (choice == 4) {
            cout << "Thank you for using our shopping app!\n";
            break;
        }

        else {
            cout << "Invalid option! Try again.\n";
        }
    }

    return 0;
}
