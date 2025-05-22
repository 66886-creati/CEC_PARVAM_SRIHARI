#include<iostream>
using namespace std;
 
class Bus{
public:
    string busNumber;
    string route;
    int capacity;
    
    void display(){
        cout << "Bus Number:" << busNumber << endl;
        cout << "Routes:" << route << endl;
        cout << "Capacity:" << capacity << endl;
    }
};

int main(){
    Bus b1;
    b1.busNumber = " KA 05 7954 ";
    b1.route = " Bangalore to Hubli ";
    b1.capacity =  60 ;
    b1.display();
    return 0;
}