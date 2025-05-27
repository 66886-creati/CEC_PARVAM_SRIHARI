
#include <iostream>
#include <string>

class Item {
public:
    int quantity;
    double price;
    std::string name;

    Item(int quantity, double price, std::string name) : quantity(quantity), price(price), name(name) {}

    // Operator overloading for + (addition)
    Item operator+(const Item& other) const {
        return Item(quantity + other.quantity, (price + other.price)/2, name + "+" + other.name);
    }

    // Operator overloading for == (equality)
    bool operator==(const Item& other) const {
        return (quantity == other.quantity) && (price == other.price);
    }

    // Friend function for operator overloading of << (output stream)
    friend std::ostream& operator<<(std::ostream& os, const Item& item) {
        os << "Item -> Name: " << item.name << ", Quantity: " << item.quantity << ", Price: $" << item.price;
        return os;
    }
};

int main() {
    Item item1(15, 350.75, "Apple");
    Item item2(5, 100.25, "Banana");
    Item item3(15, 350.75, "Orange");

    // Demonstrating operator overloading
    Item item4 = item1 + item2;
    std::cout << item4 << std::endl;

    if (item1 == item3) {
        std::cout << "item1 and item3 are same in quantity and price." << std::endl;
    } else {
         std::cout << "item1 and item3 are not the same in quantity and price." << std::endl;
    }

    return 0;
}