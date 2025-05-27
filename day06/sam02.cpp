#include <iostream>
#include <unordered_map>
#include <iomanip>  // For formatting output
using namespace std;

// Product structure with discount
struct Product {
    string name;
    double price;
    double discount; // in percentage
};

// Invoice generator class
class Print {
private:
    unordered_map<int, Product> productCatalog;

public:
    // Constructor to initialize product catalog
    Print() {
        productCatalog[101] = {"Wireless Mouse", 25.99, 10.0};
        productCatalog[102] = {"Mechanical Keyboard", 89.49, 5.0};
        productCatalog[103] = {"HD Monitor", 149.99, 15.0};
        productCatalog[104] = {"USB-C Hub", 39.75, 0.0};
    }

    // Display invoice using product ID and quantity
    void display(int productId, int quantity) {
        if (productCatalog.find(productId) != productCatalog.end()) {
            Product p = productCatalog[productId];
            double totalPrice = p.price * quantity;
            double discountAmount = (totalPrice * p.discount) / 100.0;
            double finalPrice = totalPrice - discountAmount;

            // Format to 2 decimal places
            cout << fixed << setprecision(2);

            cout << "\n========== INVOICE ==========" << endl;
            cout << "Product ID     : " << productId << endl;
            cout << "Product Name   : " << p.name << endl;
            cout << "Unit Price     : $" << p.price << endl;
            cout << "Quantity       : " << quantity << endl;
            cout << "-----------------------------" << endl;
            cout << "Total Price    : $" << totalPrice << endl;
            cout << "Discount       : " << p.discount << "%" << endl;
            cout << "Discount Amount: $" << discountAmount << endl;
            cout << "Final Price    : $" << finalPrice << endl;
            cout << "=============================\n" << endl;
        } else {
            cout << "Product ID " << productId << " not found!\n" << endl;
        }
    }

    // Display customer name (overloaded)
    void display(string name) {
        cout << "Customer Name: " << name << endl;
    }
};

int main() {
    Print ob;

    // Display customer name
    ob.display("ZORO");

    // Example invoice for product ID 102 with quantity 2
    ob.display(101, 2);
    ob.display(102, 4);  // Try different product IDs and quantities
    ob.display(103, 3);
    ob.display(104, 5);


    return 0;
}
