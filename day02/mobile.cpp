#include<iostream>
using namespace std;

class Mobile {
public:
    string brand;
    string model;
    float price;

    void showDetails() {
        cout << "Brand: " << brand << ", Model: " << model << ", Price: ₹" << price << endl;
    }
};

int main() {
    Mobile m1;
    m1.brand = "Samsung";
    m1.model = "Galaxy A14";
    m1.price = 14999;

    m1.showDetails();
    return 0;
}