#include "Payment.h"
#include <cstdlib>  // For rand()
#include <ctime>
#include <iostream>

Payment::Payment(int id, float amount, std::string method)
    : id(id), amount(amount), method(method), status("Pending") {
    std::srand(std::time(0));
    if (method == "Credit Card" || method == "PayPal") {
        balance = static_cast<float>(std::rand() % 10001); // Random value between $0 - $10,000
    } else {
        balance = 0; // Default for other methods
    }
}


void Payment::processPayment() {
    std::cout << "Payment method: " << method << std::endl;
    std::cout << "Available balance: $" << balance << std::endl;

    if (balance >= amount) {
        balance -= amount;
        status = "Completed";
        std::cout << "Payment successful! New balance: $" << balance << std::endl;
    } else {
        status = "Failed - Insufficient Funds";
        std::cout << "Payment failed! Not enough balance.\n";
    }
}

void Payment::displayPaymentInfo() const {
    std::cout << "Payment ID: " << id << " | Amount: $" << amount << " | Status: " << status << " | Balance: $" << balance << std::endl;
}
