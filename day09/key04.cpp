#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    string *names =new string[n];

    cout << "Enter student names:\n";
    for (int i=0;i<n;i++)
    {
        cout << i+1 << ". " ;
        cin >> names[i];

    }

    char choice;
    do
    {
        string key;
        cout << "Enter name to search: ";
        cin>> key;

        bool found=false;
        for (int i=0;i<n;i++)
        {
            if (names[i]==key)
            {
            cout << "Student " << key << " found at position: " << i+1 << endl;
            found=true;
            break;
            }
        }
    

    if (!found){
        cout << "Student " << key << "not found at the list. " << endl;
    }

    cout << "Do you want to search again? (y/n): ";
    cin >> choice;
    }while (choice=='y'  ||  choice=='Y');

    delete[] names;
    return 0;
}
    
