#include<iostream>
using namespace std;

class Student{
    private:
        int rollnumber;

    public:
        void setRollNumber(int r)
        {
            rollnumber = r;

        }   
        
        int getRollNumber()
        {
            return rollnumber;
        }
};

int main()
{
    Student s1;
    s1.setRollNumber(555);
    cout << s1.getRollNumber() << endl;

    return 0;
}