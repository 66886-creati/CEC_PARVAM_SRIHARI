#include<iostream>
using namespace std;

class Calculator{
    public:
      int add(int a,int b);
      int subtract(int a,int b);
      int multiply(int a,int b);
      int division(int a,int b);
    
};

int Calculator::add(int a,int b){
    return a + b;
}

int Calculator::subtract(int a,int b){
    return a - b;
}

int Calculator::multiply(int a,int b){
    return a * b;
}

int Calculator::division(int a,int b){
    return a / b;
}

int main(){
    Calculator calc;
    cout << "Add:" << calc.add(10,5) << endl;
    cout << "Subtract:" << calc.subtract(10,5) << endl;
    cout << "Multiply:" << calc.multiply(10,5) << endl;
    cout << "Division:" << calc.division(10,5) << endl;
    

    return 0;
}