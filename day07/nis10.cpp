#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    string *employees =new string[n];

    for (int i=0;i<n; i++){
        cout << "enter employees " << (i+1) << " name: ";
        cin >> employees[i];
    }

    cout << "\nemployee List:\n";
    for (int i=0; i<n; i++){
        cout << (i+1) << ". " << employees[i] << endl;
    }

    delete employees;
    return 0;
}
