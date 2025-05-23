#include <iostream>
using namespace std;

class Teach
{
    public:
        string name;
        string dob;
        string id;
        string dept;
        float exp;
        float sal;

        Teach()
        {
            id = "Undefined";
            dept = "Unassigned";
            exp = 0;
        }

        Teach(string stn, string sdob, float ssal)
        {
            name = stn;
            dob = sdob;
            sal = ssal;
        }

        Teach(string stn, string sdob, float ssal, string sid, string sdept, float xp)
        {
            name = stn;
            dob = sdob;
            sal = ssal;
            id = sid;
            dept = sdept;
            exp = xp;
        }

        Teach(const Teach &ct)
        {
            name = ct.name;
            dob = ct.dob;
            sal = ct.sal;
            id = ct.id;
            dept = ct.dept;
            exp = ct.exp;
        }

        void get()
        {
            cout << " | "<<name<<" | "<< dob<< " | "<< dept << " | "<< id << " | " << exp << " | "<< sal<<endl; 
        }

        void setsal(float ssal)
        {
            sal = ssal;
        }

        float getsal()
        {
            return sal;
        }
};

int main()
{
    Teach t1("Steve", "29-9-2003", 125000, "CEC420", "ICE", 7);
    Teach t2("Tony","24-10-1996",120000, "CEC124", "CSE", 6);
    Teach t3("Clint", "29-9-2000", 150000, "CEC123", "AIML", 5.5);
    Teach t4("Bruce", "29-9-2000", 175000, "CEC143", "AIML", 10);
    Teach t5 = t2;

    cout << "\n -------- Before : Teacher Details --------" << endl;
    cout << " |   Name   |   DOB   | Department | Employee ID | Experience |  Salary  |"<< endl;

    t1.get();
    t2.get();
    t3.get();
    t4.get();
    t5.get();

    cout << "T1 Salary = " << t1.getsal() << endl;
    cout << "T2 Salary = " << t2.getsal() << endl;
    cout << "T3 Salary = " << t3.getsal() << endl;
    cout << "T4 Salary = " << t4.getsal() << endl;
    cout << "T5 Salary = " << t5.getsal() << endl;

    if (t1.getsal() <=150000)
    {
        t1.setsal(t1.getsal()*2);
    }
    else
    {
        t1.setsal(t1.getsal()-5000);
    }

    if (t2.getsal() <=150000)
    {
        t2.setsal(t2.getsal()*2);
    }
    else
    {
        t2.setsal(t2.getsal()-5000);
    }
    if (t3.getsal() <=150000)
    {
        t3.setsal(t3.getsal()*2);
    }
    else
    {
        t3.setsal(t3.getsal()-5000);
    }
    if (t4.getsal() <=150000)
    {
        t4.setsal(t4.getsal()*2);
    }
    else
    {
        t4.setsal(t4.getsal()-5000);
    }
    if (t5.getsal() <=150000)
    {
        t5.setsal(t5.getsal()*2);
    }
    else
    {
        t5.setsal(t5.getsal()-5000);
    }

    cout << "\n -------- After : Teacher Details --------" << endl;

    
    cout << "T1 Salary = " << t1.getsal() << endl;
    cout << "T2 Salary = " << t2.getsal() << endl;
    cout << "T3 Salary = " << t3.getsal() << endl;
    cout << "T4 Salary = " << t4.getsal() << endl;
    cout << "T5 Salary = " << t5.getsal() << endl;





    return 0;
}