#include <iostream>
using namespace std;

class person
{
    protected:
        string name;
        int age;
    public:
        void SetBasicInfo(string n ,int a)
        {
            name=n;
            age=a;
        }
};

class patient : public person
{
    protected:
        string disease ;
        double billAmount;

    public:
        void setMedicalInfo(string d, double bill)
        {
            disease=d;
            billAmount=bill;
        }
        void PatientDetails(){
            cout << "Patient Name: " << name << endl;
            cout << "Patient Age: " << age << endl;
            cout << "Patient Disease: " << disease << endl;
            cout << "Bill Amt: " << billAmount << endl;
        
        }
        double getBIll(){
            return billAmount;
        }
        string getDisease()
        {
            return disease;
        }
    };

class Doctor{
    public:
        void diagonse(patient &p){
            cout << "Reviewing patient's condition: " << p.getDisease() << endl;
        }
    };    

int main(){
    patient p1;
    p1.SetBasicInfo("John Doe",35);
    p1.setMedicalInfo("Pneumonia",5000);
    p1.PatientDetails();

    Doctor d1;
    d1.diagonse(p1);

    return 0;
}