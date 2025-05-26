#include<iostream>

using namespace std;

class Payment {
public:
    virtual ~Payment() {}
    virtual void pay() = 0;
};

class CreditCardPayment : public Payment {
public:
    void pay() override {
        cout << "Successful credit card payment..." << endl;
    }
};

class PayPalPayment : public Payment {
public:
    void pay() override {
        cout << "Successful PayPal payment..." << endl;
    }
};

int main() {
    for (int i = 1; i <= 10000; i++) {
        Payment * paymentMethod;

        int choice = rand() % 2 + 1;

        switch (choice) {
        case 1:
            paymentMethod = new CreditCardPayment();
            break;
        case 2:
            paymentMethod = new PayPalPayment();
            break;
        }

        cout << "Payment #" << i << ": ";
        paymentMethod->pay();
    }

    return 0;
}