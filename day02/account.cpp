#include<iostream>
using namespace std;
 
class Account{
    private:
     int balance;
    public:
     void setBalance(int b){
        balance = b;
     } 
     int getBalance(){
        return balance;
     }
};

int main(){
    Account acc;
    acc.setBalance(1000);
    cout << "Balance:" << acc.getBalance() << endl;
    return 0;
}