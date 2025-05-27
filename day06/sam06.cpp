#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Item 
{
    private:
    string name;
    int quantity;
    float price;
    public:
    Item(string n = "", int q = 0, float p = 0.0f) : name(n), quantity(q), price(p) {}

    Item operator+(const Item &other) 
    {
        return Item(name + " & " + other.name, quantity + other.quantity, price + other.price);
        }

        bool operator==(const Item &other)
        {
            return (name == other.name && quantity == other.quantity && price == other.price);
            }

            friend ostream &operator<<(ostream &os, const Item &item)
            {
                os << left << setw(15) << item.name << setw(10) << item.quantity << "$" << fixed << setprecision(2) << item.price;
                return os;
            }
            string getName() const { return name; }
            int getQuantity() const { return quantity; }
            float getPrice() const { return price; }
        };
        class Invoice
        {
            public:
            void generateInvoice( const Item &item)
            {
                cout << "------Invoice  (basic)------" << endl;
                cout << item << endl;
                cout<< "Total: $" << item.getPrice() << endl
                << endl;
            }

            void generateInvoice(const Item &item, int quantity)
            {
                float total = item.getPrice() * quantity;
                cout << "------Invoice  (with Quantity)------" << endl;
                cout << item.getName() << " x " << quantity << endl;
                cout << "Unit Price: $" << item.getPrice() << endl;
                cout << "Total: $" << total << endl
                 << endl;
                 }

                 void generateInvoice(const Item &item, int quantity, float discount)
                 {
                    float subtotal = item.getPrice() * quantity; 
                    float discountAmount = subtotal * (discount / 100);
                    float total = subtotal - discountAmount;
                    cout << "------Invoice  (with Quantity and Discount)------" << endl;
                    cout << item.getName() << " x " << quantity << endl;
                    cout << "Subtotal: $" << subtotal << endl;
                    cout << "Discount: " << discount << "% (-$" << discountAmount << ")" << endl;
                    cout << "Total Payable: $" << total << endl
                    << endl;
                 }
};

int main()
{
    Item item1("Laptop", 10, 1200.00);
    Item item2("Monitor", 5, 300.00);
    Item item3("Laptop", 10, 1200.00);

    cout << "=== Inventory Items ===" << endl;
    cout << left << setw(15) << "Name" << setw(10) << "Qty" << "Price" << endl;
    cout << item1 << endl;
    cout << item2 << endl;

    cout << "\n=== Add Items ===" << endl;
    Item combined = item1+item2;
    cout << combined << endl;

    cout << "\n=== Compare Items ===" << endl;
    if (item1 == item3)
        cout << "item1 and item3 are identical. \n";
    else
        cout << "item1 and item3 are different. \n";

    Invoice inv;
    cout << "\n=== Generate Invoice ===\n";  
    inv.generateInvoice(item1);
    inv.generateInvoice(item2, 3);
    inv.generateInvoice(item2, 3 , 10.0f);
     
    return 0;
    
}