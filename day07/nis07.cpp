#include <iostream>
#include <string>
#include <iomanip>

class Product {
private:
    std::string name;
    double price;
    double discount;

public:
    Product(std::string name, double price) : name(name), price(price), discount(0) {}

    Product& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double calculateFinalPrice() const {
        return price * (1 - discount);
    }

    void displayProductInfo() const {
        std::cout << "Product Name: " << name << std::endl;
        std::cout << "Original Price: $" << std::fixed << std::setprecision(2) << price << std::endl;
        std::cout << "Discount: " << std::fixed << std::setprecision(2) << (discount * 100) << "%" << std::endl;
        std::cout << "Final Price: $" << std::fixed << std::setprecision(2) << calculateFinalPrice() << std::endl;
        std::cout << std::endl;
    }

    std::string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    double getDiscount() const {
        return discount;
    }
};

int main() {
    Product laptop("Laptop", 1200000.00);
    Product tablet("Tablet", 30000.00);

    laptop.setDiscount(0.1).displayProductInfo();
    tablet.setDiscount(0.2).displayProductInfo();

    if (laptop.calculateFinalPrice() < tablet.calculateFinalPrice()) {
         std::cout << tablet.getName() << " is more expensive than " << laptop.getName() << " after discount." << std::endl;
    } else if (laptop.calculateFinalPrice() > tablet.calculateFinalPrice()){
        std::cout << laptop.getName() << " is more expensive than " << tablet.getName() << " after discount." << std::endl;
    } else {
        std::cout << laptop.getName() << " and " << tablet.getName() << " have the same price after discount." << std::endl;
    }

    return 0;
}