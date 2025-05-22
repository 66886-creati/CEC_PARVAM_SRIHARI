#include<iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    float balance;

public:
    void setDetails(string name, int accNum, float bal) {
        accountHolder = name;
        accountNumber = accNum;
        balance = bal;
    }

    void deposit(float amount) {
        balance += amount;
        cout << "Deposited ₹" << amount << ". New Balance: ₹" << balance << endl;
    }

    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn ₹" << amount << ". Remaining Balance: ₹" << balance << endl;
        } else {
            cout << "Insufficient Balance!" << endl;
        }
    }

    void display() {
        cout << "Account Holder: " << accountHolder << ", Account No: " << accountNumber << ", Balance: ₹" << balance << endl;
    }
};

int main() {
    BankAccount b1;
    b1.setDetails("Amit", 1001, 5000);
    b1.display();

    b1.deposit(2000);
    b1.withdraw(1000);
    b1.withdraw(7000);  // Insufficient balance
    return 0;
}
