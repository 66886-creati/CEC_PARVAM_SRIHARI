#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Employee {
    string name;
    string shift;
};

int main() {
    int numEmployees;
    cout << "Enter the number of employees checked in today: ";
    cin >> numEmployees;

    vector<Employee> employees(numEmployees);

    for (int i = 0; i < numEmployees; ++i) {
        cout << "\nEnter details for employee " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> employees[i].name;
        cout << "Shift (Morning, Afternoon, Night): ";
        cin >> employees[i].shift;
    }

    cout << "\n--- Employee List ---" << endl;
    for (const auto& employee : employees) {
        cout << "Name: " << employee.name << ", Shift: " << employee.shift << endl;
    }

    map<string, int> shiftCounts;
    for (const auto& employee : employees) {
        shiftCounts[employee.shift]++;
    }

    cout << "\n--- Shift Counts ---" << endl;
    for (const auto& pair : shiftCounts) {
        cout << "Shift: " << pair.first << ", Count: " << pair.second << endl;
    }

    return 0;
}