#include<iostream>
using namespace std;
class student
{
public:
    int *marks;
    int size;

    student(int s) {
        size = s;
        marks = new int[size];
    }
    student(const student &s) {
        size = s.size;
        marks = new int[size];
        for (int i = 0; i < size; i++) {
            marks[i] = s.marks[i];
        }
    }


};
int main() {
    student s1(5);
    for (int i = 0; i < 5; i++) {
        s1.marks[i] = i * 10;
    }
    student s2 = s1; // Calls the copy constructor
    for (int i = 0; i < 5; i++) {
        cout << "s2.marks[" << i << "] = " << s2.marks[i] << endl;
    }
    return 0;
}