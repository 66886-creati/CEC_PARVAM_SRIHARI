#include<iostream>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
    float marks;

    void printInfo() {
        cout << "Student: " << name << ", Roll No: " << rollNo << ", Marks: " << marks << "%" << endl;
    }
};

int main() {
    Student s1;
    s1.name = "Riya";
    s1.rollNo = 101;
    s1.marks = 88.5;

    s1.printInfo();
    return 0;
}
