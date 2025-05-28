#include <iostream>
using namespace std;

class Product
{
    public:
    string name;
    double price;

    public:
    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
    void display()
    {
        cout << "Product: " << this->name << ", Price: $" << this->price << endl;
    }
};
int main()
{
    Product p1("Laptop", 999.99);
    Product p2( "Smartphone", 499.99);

    p1.display();
    p2.display();

    return 0;
}