#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

class Payment {
private:
    int id;
    float amount;
    std::string method;
    std::string status;
    float balance;

public:
    Payment(int id, float amount, std::string method);
    void processPayment();
    void displayPaymentInfo() const;
    std::string getStatus() const { return status; }
};

#endif
