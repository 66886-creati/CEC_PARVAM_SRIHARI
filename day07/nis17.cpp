#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    string name;
    string subject;

public:
    Teacher(string name, string subject) {
        this->name = name;
        this->subject = subject;
    }

    void display() {
        cout << "Teacher: " << name << " | Subject: " << subject << endl;
    }
};

class Student {
private:
    string name;
    int *marks;
    int *id;

public:
    Student(string name, int marks, int id) {
        this->name = name;
        this->marks = new int(marks);
        this->id = new int(id);
    }

    void addBonus(int bonus) {
        *marks += bonus;
    }

    void display() {
        cout << "Student: " << name << " | ID: " << *id << " | Marks: " << *marks << endl;
    }

    ~Student() {
        cout << "Deleting student: " << name << endl;
        delete marks;
        delete id;
    }
};

int main() {
    int scores[] = {90, 85, 78};
    int *pScores = scores;
    cout << "Scores: ";
    for (int i = 0; i < 3; i++)
        cout << *(pScores + i) << " ";
    cout << endl;

    Student *s1 = new Student("Alice", 90, 1001);
    Student *s2 = new Student("Bob", 85, 1002);

    s1->addBonus(5);
    s2->addBonus(10);

    s1->display();
    s2->display();

    Teacher *t1 = new Teacher("Dr. Smith", "Mathematics");
    Teacher *t2 = new Teacher("Ms. Johnson", "Physics");

    t1->display();
    t2->display();

    delete s1;
    delete s2;
    delete t1;
    delete t2;

    return 0;
}
