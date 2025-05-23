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
    Student s1(" Srihari" ,19," 1CEC IOT"," CEC ");
    Student s2(" Nisha" ,18," 2KERO "," KLEIT ");
    Student s3(" KICCHA" ,52," KA 32 "," MYSORE ");
    Student s4(" Ramesh" ,18," 4GEAU"," Govt Engg ");
    Student s5(" Prabhas" ,41," 7REBEL"," Mahismathi ");
    return 0;
}