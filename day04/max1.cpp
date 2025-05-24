#include<iostream>
using namespace std;

class Person {
    private:
       string name;
       int age;

       public:
         void setdata(string n, int a){
            name = n;
            age = a;
         }
         void displaydata(){
            cout<<"Name: "<< name << "Age: " << age << endl;
         }
};
int main(){
   Person p1;
   p1.setdata("Srihari", 19 );
   p1.displaydata();
   return 0;
}