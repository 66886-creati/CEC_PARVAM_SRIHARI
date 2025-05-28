#include<iostream>
using namespace std;

int main(){
    int num = 10;
    int *ptr = &num;

    cout << "Value of num: " << num << endl;
    cout << "Address of num: " << ptr << endl;
    cout << "Value via pointer: " << *ptr << endl;

    return 0;
}