#include<iostream>
using namespace std;
 
class Student {
    public:
        string name;
        int age;
        string USN;
        string clgname;
        Student(string n,int a,string b,string c)
        {
            name=n;
            age=a;
            USN=b;
            clgname=c;
            cout << "Name: " << name << " Age: " << age << " USN: " << USN << " Clgname: " << clgname << endl;

        }    
};

int main()
{
    Student s1(" Srihari" ,19," 1CEC IOT"," KLEIT ");
    return 0;
}