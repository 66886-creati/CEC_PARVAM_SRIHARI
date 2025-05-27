#include <iostream>
using  namespace std;

class Animal

{
    public:
    virtual void sound() = 0;
    virtual ~Animal() {}
};
class Dog : public Animal
{
    public:
    void sound() override
    {
        cout << "Dog says: Woof!" << endl;
    }
};

class Cat : public Animal
{
    public:
    void sound() override
    {
        cout << "Cat says: Meow!" << endl;
    }
};
 int main()
 {
    Animal *a1 = new Dog();
    Animal *a2 = new Cat();
    a1->sound();
    a2->sound();
    delete a1;
    delete a2;
    return 0;

 }