#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Student {
    int studentID;
    string name;
    string phone;
    string email;
    string address;
    string bloodGroup;
    int totalMarks;
    int rank;
    float expectedPackage;
    string admissionType;                 
    string course;
    float fee;
};

vector<Student> students;

void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();
void updateStudent();
void sortByMarks();
void sortByRank();
void feeCalculator(Student &s);
void menu();

int main() {
    cout << "=== Initializing 10 Students ===\n";
    for (int i = 0; i < 20; ++i) {
        cout << "\n--- Student #" << i + 1 << " ---\n";
        addStudent();
    }

    menu(); 
    return 0;
}

void menu() {
    int choice;
    do {
        cout << "\n=== Student Management Menu ===\n";
        cout << "1. Add Student\n2. Display All Students\n3. Search by ID\n4. Delete by ID\n5. Update by ID\n6. Sort by Marks\n7. Sort by Rank\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: updateStudent(); break;
            case 6: sortByMarks(); break;
            case 7: sortByRank(); break;
            case 8: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);
}

void addStudent() {
    Student s;
    cout << "Student ID: ";
    cin >> s.studentID;
    cin.ignore();

    cout << "Name: ";
    getline(cin, s.name);

    cout << "Phone: ";
    getline(cin, s.phone);

    cout << "Email: ";
    getline(cin, s.email);

    cout << "Address: ";
    getline(cin, s.address);

    cout << "Blood Group: ";
    getline(cin, s.bloodGroup);

    cout << "Total Marks (out of 600): ";
    cin >> s.totalMarks;

    cout << "Rank: ";
    cin >> s.rank;

    cout << "Expected Package (in LPA): ";
    cin >> s.expectedPackage;
    cin.ignore();

    cout << "Admission Type (KCET/Management): ";
    getline(cin, s.admissionType);

    cout << "Course (CSE/ECE/ME/CE): ";
    getline(cin, s.course);

    feeCalculator(s);
    students.push_back(s);

    cout << "Student added successfully.\n";
}

void feeCalculator(Student &s) {
    float baseFee = 0.0;
    if (s.course == "CSE" || s.course == "ECE")
        baseFee = 150000;
    else if (s.course == "ME" || s.course == "CE")
        baseFee = 130000;
    else
        baseFee = 100000;

    if (s.admissionType == "Management" || s.admissionType == "management") {
        float discount = 0.1f * baseFee;
        s.fee = baseFee - discount;
    } else {
        s.fee = baseFee;
    }
}

void displayStudents() {
    if (students.empty()) {
        cout << "No students to display.\n";
        return;
    }

    for (const auto& s : students) {
        cout << "\n--- Student ID: " << s.studentID << " ---\n";
        cout << "Name: " << s.name << "\nPhone: " << s.phone << "\nEmail: " << s.email;
        cout << "\nAddress: " << s.address << "\nBlood Group: " << s.bloodGroup;
        cout << "\nTotal Marks: " << s.totalMarks << "\nRank: " << s.rank;
        cout << "\nExpected Package: " << s.expectedPackage << " LPA";
        cout << "\nAdmission Type: " << s.admissionType;
        cout << "\nCourse: " << s.course << "\nFee: $" << s.fee << "\n";
    }
}

void searchStudent() {
    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;

    bool found = false;
    for (const auto& s : students) {
        if (s.studentID == id) {
            cout << "Student found: " << s.name << ", Rank: " << s.rank << ", Course: " << s.course << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Student ID not found.\n";
}

void deleteStudent() {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    auto it = remove_if(students.begin(), students.end(), [id](Student s) {
        return s.studentID == id;
    });

    if (it != students.end()) {
        students.erase(it, students.end());
        cout << "Student deleted successfully.\n";
    } else {
        cout << "Student ID not found.\n";
    }
}

void updateStudent() {
    int id;
    cout << "Enter Student ID to update: ";
    cin >> id;
    cin.ignore();

    for (auto& s : students) {
        if (s.studentID == id) {
            cout << "Updating " << s.name << "'s info:\n";
            cout << "New Phone: ";
            getline(cin, s.phone);
            cout << "New Email: ";
            getline(cin, s.email);
            cout << "New Address: ";
            getline(cin, s.address);
            cout << "New Expected Package: ";
            cin >> s.expectedPackage;
            cout << "Update complete.\n";
            return;
        }
    }

    cout << "Student ID not found.\n";
}

void sortByMarks() {
    sort(students.begin(), students.end(), [](Student a, Student b) {
        return a.totalMarks > b.totalMarks;
    });
    cout << "Students sorted by Total Marks (Descending).\n";
}

void sortByRank() {
    sort(students.begin(), students.end(), [](Student a, Student b) {
        return a.rank < b.rank;
    }); 
    cout << "Students sorted by Rank (Ascending).\n";
}
