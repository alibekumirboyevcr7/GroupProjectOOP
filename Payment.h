#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

using namespace std;

class Payment {
private:
    int id;
    float amount;
    string method;
    string status;
    float balance;

public:
    Payment(int id, float amount, string method);
    void processPayment();
    void displayPaymentInfo() const;
    string getStatus() const { return status; }
};

#endif
