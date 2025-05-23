#include<iostream>
using namespace std;

class Car{
    public:
        string brand;
        int speed;

        Car(){
            brand="BMW";
            speed=250;
            cout << "Default Constructor Called." << endl;
        }
        
        void drive(){
            cout << " Driving " << brand << " at " << speed << " km/h. " << endl;
        }
};  

int main(){
    Car car1;
    car1.drive();
    return 0;
}