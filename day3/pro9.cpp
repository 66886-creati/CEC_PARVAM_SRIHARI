#include<iostream>
using namespace std;
 
class Car{
    string model;
    int year;

public:
    Car(){
        model = "Unknown";
        year=0;
    }  
    
    Car(string m){
        model = m;
        year = 2020;
    }

    Car(string m,int y){
        model = m;
        year = y;
    }
    void display(){
        cout << "Model: " << model << " Year: " << year << endl;
    }
};

int main(){
    Car c1;
    Car c2("BMW");
    Car c3("Toyota",2024);

    c1.display();
    c2.display();
    c3.display();

    return 0;
} 