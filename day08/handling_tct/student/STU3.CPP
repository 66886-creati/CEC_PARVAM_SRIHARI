#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    char grade;
};


void addStudent() {
    Student s;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter student age: ";
    cin >> s.age;
    cout << "Enter student grade (A/B/C/D/F): ";
    cin >> s.grade;

    ofstream outFile("students.txt", ios::app);
    if (outFile.is_open()) {
        outFile << s.name << " " << s.age << " " << s.grade << endl;
        outFile.close();
        cout << "Student record added!\n";
    } else {
        cerr << "Error opening file for writing.\n";
    }
}


void displayStudents() {
    ifstream inFile("students.txt");
    if (!inFile.is_open()) {
        cerr << "Error opening file for reading.\n";
        return;
    }

    string line;
    cout << "\n---- Students Records ------\n";
    while (getline(inFile, line)) {
        istringstream iss(line);
        Student s;
        iss >> s.name >> s.age >> s.grade;
        cout << "Name: " << s.name << ", Age: " << s.age << ", Grade: " << s.grade << endl;
    }
    inFile.close();
}


void searchStudentByName() {
    string name;
    cout << "Enter student name to search: ";
    cin.ignore();
    getline(cin, name);

    ifstream inFile("students.txt");
    if (!inFile.is_open()) {
        cerr << "Error opening file for reading.\n";
        return;
    }

    string line;
    bool found = false;
    while (getline(inFile, line)) {
        istringstream iss(line);
        Student s;
        iss >> s.name >> s.age >> s.grade;
        if (s.name == name) {
            cout << "Student Found: Name: " << s.name << ", Age: " << s.age << ", Grade: " << s.grade << endl;
            found = true;
        }
    }
    inFile.close();

    if (!found) {
        cout << "Student not found.\n";
    }
}


void updateStudentGrade() {
    string name;
    char newGrade;
    cout << "Enter student name to update grade: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter new grade: ";
    cin >> newGrade;

    ifstream inFile("students.txt");
    if (!inFile.is_open()) {
        cerr << "Error opening file for reading.\n";
        return;
    }

    vector<Student> students;
    string line;
    bool updated = false;

    while (getline(inFile, line)) {
        istringstream iss(line);
        Student s;
        iss >> s.name >> s.age >> s.grade;
        if (s.name == name) {
            s.grade = newGrade;
            updated = true;
        }
        students.push_back(s);
    }
    inFile.close();

    ofstream outFile("students.txt");
    for (const Student &s : students) {
        outFile << s.name << " " << s.age << " " << s.grade << endl;
    }
    outFile.close();

    if (updated)
        cout << "Grade updated successfully.\n";
    else
        cout << "Student not found.\n";
}


void updateStudentNameAndAge() {
    string currentName;
    cout << "Enter current student name to update: ";
    cin.ignore();
    getline(cin, currentName);

    string newName;
    int newAge;
    cout << "Enter new name: ";
    getline(cin, newName);
    cout << "Enter new age: ";
    cin >> newAge;

    ifstream inFile("students.txt");
    if (!inFile.is_open()) {
        cerr << "Error opening file for reading.\n";
        return;
    }

    vector<Student> students;
    string line;
    bool updated = false;

    while (getline(inFile, line)) {
        istringstream iss(line);
        Student s;
        iss >> s.name >> s.age >> s.grade;
        if (s.name == currentName) {
            s.name = newName;
            s.age = newAge;
            updated = true;
        }
        students.push_back(s);
    }
    inFile.close();

    ofstream outFile("students.txt");
    for (const Student &s : students) {
        outFile << s.name << " " << s.age << " " << s.grade << endl;
    }
    outFile.close();

    if (updated)
        cout << "Student name and age updated successfully.\n";
    else
        cout << "Student not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n===== Student Management Menu =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Name\n";
        cout << "4. Update Student Grade\n";
        cout << "5. Update Student Name and Age\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudentByName();
                break;
            case 4:
                updateStudentGrade();
                break;
            case 5:
                updateStudentNameAndAge();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please choose a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}
