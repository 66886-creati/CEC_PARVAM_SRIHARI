#include <iostream>
using namespace std;


class car{
    public:
        string model;
        car(string model)
        {
            this->model=model;

        }
        void show()
        {
            cout << "Car Model: " << this->model << endl;
        }
};

int main(){
    car c("Mercedes");
    c.show();
    return 0;

}