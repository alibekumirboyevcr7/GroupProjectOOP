#include "Payment.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>

using namespace std;

Payment::Payment(int id, float amount, string method)
    : id(id), amount(amount), method(method), status("Pending") {

    if (method != "Credit Card" && method != "PayPal") {
        throw invalid_argument("Unsupported payment method: " + method);
    }

    balance = static_cast<float>(rand() % 10001);
}

void Payment::processPayment() {
    cout << "Payment method: " << method << endl;
    cout << "Available balance: $" << balance << endl;

    if (balance >= amount) {
        balance -= amount;
        status = "Completed";
        cout << "Payment successful! New balance: $" << balance << endl;
    } else {
        status = "Failed - Insufficient Funds";
        cout << "Payment failed! Not enough balance.\n";
    }
}

void Payment::displayPaymentInfo() const {
    cout << "Payment ID: " << id << " | Amount: $" << amount << " | Status: " << status << " | Balance: $" << balance << endl;
}
