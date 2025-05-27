#include <iostream>
using namespace std; 

class Invoice {
    public:
        void generateInvoice(int productID)
        {
            cout << "Generating Invoice for product ID: " << productID << endl;
            cout << "Default quantity: 1 | No discount applied! " << endl;
        }
         void generateInvoice(int productID, int quantity)
        {
            cout << "Generating Invoice for product ID: " << productID << endl;
            cout << "Quantity:" << quantity << " | No discount applied! " << endl;
        }
         void generateInvoice(int productID, int quantity, float discount)
        {
            cout << "Generating Invoice for product ID: " << productID << endl;
            cout << "Quantity:" << quantity << " | Discount:  " << discount << "%" << endl;
        }
        
};

int main(){
    Invoice inv; 
    
    inv.generateInvoice(101);
    inv.generateInvoice(102, 3);
    inv.generateInvoice(103 ,5 , 10.5);
}