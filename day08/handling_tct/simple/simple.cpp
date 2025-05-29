#include<iostream>

int main(){
    try
    {
        int age=15;
        if (age<18)
        {
            throw age;
        }
        else{
            std::cout << "access granted.\n";
        }
    }
    catch (int myNum){
         std::cout << "access denied.  age is: " << myNum << "\n";
    }
    return 0;
    
}