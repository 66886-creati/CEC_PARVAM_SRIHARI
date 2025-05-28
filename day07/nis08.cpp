#include <iostream>
using namespace std;

class Product
{
    private:
    string name;
    double price;
    double discount;
    public:
    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
        this->discount = 0.0;
    }
    Product &setDiscount (double percent)
    {
        this-> discount = percent;
        return *this;
    }
    double getFinalPrice() const
    {
        return price - (price * discount / 100.0);
    }

    bool operator>(const Product &other) const
    {
        return this->getFinalPrice() > other.getFinalPrice();
    }
    void show() const 
    {
        cout << "Product: " << name
        << " Original Price: $" << price
        << " Discount: " << discount << "%"
        << " Final Price: $" << getFinalPrice() << endl; 
    }
};

int main(){
    Product Laptop("Laptop", 1200.00);
    
    Product Tablet("Tablet", 900.00);

    Laptop.setDiscount(15).show();
    Tablet.setDiscount(5).show();

    if (Laptop>Tablet){
        cout << Laptop.getFinalPrice() << " is more expensive than " << Tablet.getFinalPrice() << endl;
    }else{
        cout << Tablet.getFinalPrice() << " is more expensive than " << Laptop.getFinalPrice() << endl;
    }

    return 0;
    
}