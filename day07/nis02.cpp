#include <iostream>
using namespace std;

    void displayInventory( int *inventory, int size ) 
    {
        for ( int i = 0; i < size; i++)
        {
            cout<< *(inventory + i) << " ";
        }
        cout<< endl;
    }

    int main()
    {
        int inventory[5] = { 50, 30, 20, 40, 10 };
        int *ptr = inventory;
        displayInventory( ptr, 5 );

        *(ptr + 2) = 25;

        cout << " Updated Inventory: ";
        for ( int i = 0; i < 5; i++)
        {
            cout<< inventory [i] << " " ;
            }
            cout<< endl;

        return 0;
    }
