#include <iostream>
using namespace std;

class Print{
    public:
        void display(int num)
        {
            cout << "Printing number: " << num << endl;
        }

        void display(string name)
        {
            cout << "Printing name: " << name << endl;
        }
};
  int main(){
    Print ob;
    ob.display(100);
    ob.display("ZORO");

    return 0;
  }