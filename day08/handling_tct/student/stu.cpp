#include <iostream>
#include<string>
#include <limits>
#include <fstream>
using namespace std;

void err(const string &msg)
{
    ofstream errF("Error.txt", ios::app);
    if (errF)
    {
        errF << msg <<endl;
        errF.close();
    }
    else
    {
        cerr <<"Failed To Open Error.txt For Writing.\n";
    }
}

int main()
{
    double n1,n2,r;
    char ch;

    do
    {
        try
        {
            cout <<"\n Enter The First No. : ";
            if(!(cin >> n1))
            {
                cin.clear();
                cin.ignore(numeric_limits <streamsize> ::max(), '\n');
                throw string {"Invalid Input:"};
            }

            cout <<"Enter The Second No. : ";
            if(!(cin >> n2))
            {
                cin.clear();
                cin.ignore(numeric_limits <streamsize> ::max(), '\n');
                throw string {"Invalid Input:"};
        
            }

            if (n2 == 0)
            {
                throw string {"Math Error: Dividing By Zero."};
            }

            r = n1 / n2;
            cout << "Result: "<< r<<endl;


        }
        catch(const string &er)
        {
            cout << "Exception: "<< er << endl;
            err(er);
        }

        cout <<"\n Do You Want To Do Again: (y/n)";
        cin>>ch;
    } while (ch == 'y' || ch == 'Y');
    
    cout <<"ThankYou For Using Division.";


    return 0;
}