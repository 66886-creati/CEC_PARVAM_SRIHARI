#include<iostream>
using namespace std;

class Book{
    public:
        string title;
        string author;
        float price;

        Book(string t,string a,float p) : title(t) , author(a) , price(p){}

        void display()
        {
            cout << "Title:" << title << "Author: " << author << "Price: $" << price << endl;

        }
};

int main(){
    Book b( " The One Piece " , " Monkey D Luffy " , 20.99);
    b.display();
    return 0;
}