#include <iostream>
using namespace std;

class items
{
    private:
        string item;
        int cnt;

    public:
        int pr = 0, amt = 0;
        int setit(int c)
        {
            cnt = c;
        }
        
        void itm(string it, int cn)
        {
            if (it == "Mango")
            {
                pr = 2000;
                amt = pr * cn;
                cout <<endl<< "You Ordered "<<cn << " "<<it;
            }

            else if (it == "Apple")
            {
                pr = 3000;
                amt = pr * cn;
                cout << endl<<"You Ordered "<<cn << " "<<it;
            }

            else if (it == "Banana")
            {
                pr = 4000;
                amt = pr * cn;
                cout << endl<<"You Ordered "<<cn << " "<<it;
            }

            else
            {
                cout << "We Do Not Have "<< it<<endl;
            }

        }

        int getamt()
        {
            return amt;
        }

        float disc()
        {
            float ds = 0.15;
            return ds;
        }

};

int main()
{
    float amt1,amt2,amt3,amt;
    items t1;


    t1.itm("Mango", 10);
    amt1 =t1.getamt();
    cout <<endl<<"Price :"<< amt1 <<endl;

    

    t1.itm("Banana", 10);
    amt2 = t1.getamt();
    cout <<endl<<"Price :"<< amt2<<endl;

    

    t1.itm("Apple", 10);
    amt3 = t1.getamt();
    cout <<endl<<"Price :"<< amt3<<endl;

    

    amt = amt1 + amt2 + amt3;

    cout << "Before Discount : "<<amt<<endl;


    if (amt1 >2000)
    {
        amt1 -= 500;
    }

    if (amt2 >2000)
    {
        amt2 -= 500;
    }

    if (amt3 >2000)
    {
        amt3 -= 500;
    }

    amt = amt1 + amt2 + amt3;

    /*if(amt >= 500)
    {
        
        amt = amt - (amt*t1.disc());
    */    
        cout << "Discounted Price : 1500"<<endl;
        cout <<endl<<"Total Price :"<< amt<<endl;

    /*else
    {
        cout <<endl<<"Total Price :"<< amt<<endl;
    }*/


    return 0;
}