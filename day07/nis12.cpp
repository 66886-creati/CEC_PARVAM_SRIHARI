#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Employee {
    string name;
    string shift;
    double salary;
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
        cout << "Salary: ";
        cin >> employees[i].salary;
    }

    cout << "\n--- Employee List ---" << endl;
    for (const auto& employee : employees) {
        cout << "Name: " << employee.name 
             << ", Shift: " << employee.shift 
             << ", Salary: " << employee.salary << endl;
    }

    map<string, int> shiftCounts;
    map<string, double> shiftSalaries;

    for (const auto& employee : employees) {
        shiftCounts[employee.shift]++;
        shiftSalaries[employee.shift] += employee.salary;
    }

    cout << "\n--- Shift Summary ---" << endl;
    for (const auto& pair : shiftCounts) {
        cout << "Shift: " << pair.first 
             << ", Count: " << pair.second 
             << ", Total Salary: " << shiftSalaries[pair.first] << endl;
    }

    return 0;
}
