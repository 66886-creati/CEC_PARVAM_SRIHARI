#include<iostream>
using namespace std;
  
class Student{
    public:
    string name;
    int age;
    Student(string n,int a ){
        name=n;
        age=a;
    }
    Student(const Student &s)
    {
        name = s.name;
        age = s.age;

    }
    void display()
    {
        cout << " Name: " << name << " Age: " << age << endl;

    }
};
int main(){
    Student s1(" Srihari ",19);
    Student s2 = s1;
    s2.display();
    return 0;
}