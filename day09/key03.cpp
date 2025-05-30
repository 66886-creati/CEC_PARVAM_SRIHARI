#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int *rolls =new int[n];

    cout << "Enter student rollnumbers:\n";
    for (int i=0;i<n;i++)
    {
        cout << i+1 << ". " ;
        cin >> rolls[i];

    }

    int  key;
    cout << "Enter the rollnumber to search: ";
    cin >> key;

    bool found=false;
    for (int i=0;i<n;i++)
    {
        if (rolls[i]==key)
        {
            cout << "rollnumber " << key << " found at position: " << i+1 << endl;
            bool found=true;
            break;
        }
    }

    if (!found){
        cout << "Student " << key << "not found at the list. " << endl;
    }

    delete[] rolls;
    return 0;
    
}
