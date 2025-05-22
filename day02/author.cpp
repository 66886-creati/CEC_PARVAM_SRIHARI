#include<iostream>
using namespace std;
 
class Book{
    public:
     string title;
     string author;
     void display(){
        cout << " Title: " << title << " Author: " << author << endl;
     }
};        

int main(){
   Book b1;
   b1.title = " Naruto ";
   b1.author = " Masashi Kishimoto ";
   b1.display();
   return 0;
}