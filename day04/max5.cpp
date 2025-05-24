#include<iostream>
using namespace std;

class Product {
    private:
       int quantity;
       float priceperitem;

    public:
      void setProduct(int q, float price){
        if(q > 0 && price > 0){
            quantity = q;
            priceperitem = price;
        }
        else {
           cout <<"Invalid quantity or price!" << endl;
        }
      }
      float getTotalPrice(){
        return quantity * priceperitem;
      }
      int getQuantity(){
        return quantity;
      }
      float getUnitPrice(){
        return priceperitem;
      }
};

int main(){
    Product  item1;
    item1.setProduct(3, 499.99);

    cout << "Item Bought: " << item1.getQuantity()<< endl;
    cout << "Price per item: " << item1.getUnitPrice()<< endl;
    cout << "total cost: " << item1.getTotalPrice()<< endl;

    return 0;
}