#include <iostream>
using namespace std;

class BankAccount
{
    protected:
        double balance;

    public:
        void setBalance(double b)
        {
            balance = b;
        }    
};
class SavingAccount : public BankAccount
{
    public:
        void showBalance()
        {
            cout << "Balance is: $" << balance << endl;

        }
};

int main (){
    SavingAccount acc;
    acc.setBalance(1000);
    acc.showBalance();
    return 0;

}