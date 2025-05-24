#include<iostream>
using namespace std;
 class Payment{
    public:
        virtual ~Payment(){}

        virtual void pay() = 0;
 };

 class CreditCardPayment : public Payment
 {
    public:
        void pay() override{
        
            cout << "Processing credit card payment..." << endl;
        }
 };

 class PayPalPayment : public Payment
 {
    public:
        void pay() override
        {
            cout << "Processing PayPal payment..." << endl;
        }
 };

 int main(){
    Payment *PaymentMethod = nullptr;
    int choice;

    cout << "Choose a payment method:\n";
    cout << "1. Credit Card\n";
    cout << "2. PayPal\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        PaymentMethod = new CreditCardPayment();
        break;    
    case 2:
        PaymentMethod = new PayPalPayment();
        break;       
    default:
        cout << "Invalid choice. Exiting..." << endl;
        return 1;    
    }

    PaymentMethod->pay();

    delete PaymentMethod;

    return 0;
 }    