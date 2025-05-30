#include<iostream>
#include<string>
using namespace std;



int binarysearch(int arr[], int size , int key)
{
    int left =0,right = size-1;

    while(left <=right)
    {
        int mid=(left+right)/2;

        if (arr[mid]==key)
            return mid;
        else if (arr[mid]<key)
            left =mid+1;
        else
            right =mid-1;
    }

    return -1;

}

void displaybooks(int arr[], string titles[],int size)
{
    cout << "\nAvailable Books.\n";
    for (int i=0;i<size;i++)
    {
        cout << "ID: " << arr[i] << " - " << titles[i] << endl;
    }
}

int main(){
    const int size=7;
    int BookIDs[size]={1001,1005,1010,1020, 1030,1050,1100};
    string BookTitles[size]={"C++ Basics","Data structures ","algorithms","Database systems","Operating systems","Computer networks","AI fundamentals"};
    displaybooks(BookIDs,BookTitles,size);
    int searchID;
    cout << "\nEnter the bookID to serach: ";
    cin >> searchID;

    int index=binarysearch(BookIDs,size,searchID);


    if (index != -1){
        cout << "Book Found: " << BookTitles[index] << "(ID: " << BookIDs[index] << "]" << endl;
    }
    else
    {
        cout << "Book with ID " << searchID << " not found." << endl;
    }
    return 0;
}