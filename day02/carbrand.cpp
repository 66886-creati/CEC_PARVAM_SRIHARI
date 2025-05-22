#include<iostream>
using namespace std;

class Car{
    public:
     string brand;
    void start(){
        cout<< brand << " car started! " << endl;
    } 

};

int main(){
    Car c1, c2, c3;
    c1.brand = "BMW";
    c1.start();
    c2.brand = "Ferrari";
    c2.start();
    c3.brand = "Mercedes";
    c3.start();

    return 0;
}
