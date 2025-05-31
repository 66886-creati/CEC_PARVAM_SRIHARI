#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <limits>       // Required for numeric_limits
#include <algorithm>    // Required for std::sort and std::remove_if
#include <stdexcept>    // Required for std::runtime_error, std::invalid_argument, std::out_of_range
#include <iomanip>      // Required for std::fixed and std::setprecision
#include <ctime>        // Required for time()
#include <cstdlib>      // Required for srand() and rand()

using namespace std;

// --- Structures ---

struct Student {
    string name;
    string phoneNumber;
    string email;
    string address;
    string bloodGroup;
    string studentID; // Unique ID
    string admittedCourse; // The course student is admitted to
    string admissionType; // "KCET" or "Management"
    double totalMarks;
    int rankObtained;
    double expectedPackage; // in Lakhs per annum
    double feesPaid;
};

struct Course {
    string courseName;
    double kcetFees;
    double managementFees;
};

// --- Global Variables ---
vector<Student> students;
vector<Course> courses;
const string STUDENTS_FILE = "students.txt";
const string COURSES_FILE = "courses.txt";
const double MANAGEMENT_DISCOUNT_PERCENTAGE = 10.0; // 10% discount for management admissions

// --- Function Prototypes ---
void loadStudentsFromFile();
void saveStudentsToFile();
void loadCoursesFromFile();
void saveCoursesToFile();
string generateStudentID();
void addStudent();
void displayAllStudents();
void searchStudentByID();
void updateStudentDetails();
void deleteStudentByID();
void sortStudentsByRank();
void generateSampleStudents(int count);
void displayCourseDetails();
void countAdmissionsByType();
void clearInputBuffer();
void promptForEnter();
void initializeDefaultCourses(); // New function to add default courses

// --- Main Function ---
int main() {
    loadCoursesFromFile(); // Load courses first
    // If courses file was empty or not found, initialize some default courses
    if (courses.empty()) {
        cout << "No course data found. Initializing default courses.\n";
        initializeDefaultCourses();
        saveCoursesToFile(); // Save default courses
    }

    loadStudentsFromFile(); // Load students

    // Generate sample students only if no student data is loaded
    if (students.empty()) {
        cout << "No student data found. Generating 30 sample students.\n";
        generateSampleStudents(30);
    }

    int choice;
    do {
        cout << "\n===== UGC University Registration System =====\n";
        cout << "1. Add New Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Update Student Details\n";
        cout << "5. Delete Student by ID\n";
        cout << "6. Sort Students by Rank\n";
        cout << "7. Display Course Details & Fees\n";
        cout << "8. Count Admissions by Type (KCET/Management)\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        clearInputBuffer(); // Clear the buffer after reading an integer

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                searchStudentByID();
                break;
            case 4:
                updateStudentDetails();
                break;
            case 5:
                deleteStudentByID();
                break;
            case 6:
                sortStudentsByRank();
                break;
            case 7:
                displayCourseDetails();
                break;
            case 8:
                countAdmissionsByType();
                break;
            case 9:
                cout << "Saving data and Exiting...\n";
                saveStudentsToFile();
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 9.\n";
        }
        promptForEnter(); // Pause after each operation
    } while (choice != 9);

    return 0;
}

// --- Helper Functions ---

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void promptForEnter() {
    cout << "\nPress Enter to continue...";
    cin.get(); // Wait for Enter key (consumes the newline from previous input)
}

// Function to save students data to file
void saveStudentsToFile() {
    ofstream outFile(STUDENTS_FILE);
    if (!outFile.is_open()) {
        cerr << "Error: Could not open students file for writing.\n";
        return;
    }
    for (const auto& s : students) {
        outFile << s.name << ","
                << s.phoneNumber << ","
                << s.email << ","
                << s.address << ","
                << s.bloodGroup << ","
                << s.studentID << ","
                << s.admittedCourse << ","
                << s.admissionType << ","
                << fixed << setprecision(2) << s.totalMarks << "," // Format double
                << s.rankObtained << ","
                << fixed << setprecision(2) << s.expectedPackage << "," // Format double
                << fixed << setprecision(2) << s.feesPaid << "\n"; // Format double
    }
    outFile.close();
    cout << "Students data saved successfully.\n";
}

// Function to load students data from file with error handling
void loadStudentsFromFile() {
    ifstream inFile(STUDENTS_FILE);
    if (!inFile.is_open()) {
        cerr << "Warning: Students file not found or could not be opened. Starting with empty data.\n";
        return;
    }
    students.clear(); // Clear existing data

    string line;
    int lineNumber = 0;
    while (getline(inFile, line)) {
        lineNumber++;
        stringstream ss(line);
        string segment;
        Student s;

        try {
            // Parsing string fields
            if (!getline(ss, s.name, ',')) throw runtime_error("Name missing");
            if (!getline(ss, s.phoneNumber, ',')) throw runtime_error("Phone number missing");
            if (!getline(ss, s.email, ',')) throw runtime_error("Email missing");
            if (!getline(ss, s.address, ',')) throw runtime_error("Address missing");
            if (!getline(ss, s.bloodGroup, ',')) throw runtime_error("Blood group missing");
            if (!getline(ss, s.studentID, ',')) throw runtime_error("Student ID missing");
            if (!getline(ss, s.admittedCourse, ',')) throw runtime_error("Admitted course missing");
            if (!getline(ss, s.admissionType, ',')) throw runtime_error("Admission type missing");

            // Parsing numeric fields with conversion and error checking
            if (!getline(ss, segment, ',')) throw runtime_error("Total marks missing");
            s.totalMarks = stod(segment);

            if (!getline(ss, segment, ',')) throw runtime_error("Rank obtained missing");
            s.rankObtained = stoi(segment);

            if (!getline(ss, segment, ',')) throw runtime_error("Expected package missing");
            s.expectedPackage = stod(segment);

            if (!getline(ss, segment)) throw runtime_error("Fees paid missing"); // Last segment
            s.feesPaid = stod(segment);

            students.push_back(s);
        } catch (const invalid_argument& e) {
            cerr << "Error parsing students.txt at line " << lineNumber << ": Invalid number format. " << e.what() << " on segment: \"" << segment << "\". Full line: \"" << line << "\"\n";
        } catch (const out_of_range& e) {
            cerr << "Error parsing students.txt at line " << lineNumber << ": Numeric value out of range. " << e.what() << " on segment: \"" << segment << "\". Full line: \"" << line << "\"\n";
        } catch (const runtime_error& e) {
            cerr << "Error parsing students.txt at line " << lineNumber << ": Data missing or malformed. " << e.what() << ". Full line: \"" << line << "\"\n";
        } catch (const exception& e) {
            cerr << "An unexpected error occurred while parsing students.txt at line " << lineNumber << ": " << e.what() << ". Full line: \"" << line << "\"\n";
        }
    }
    inFile.close();
    cout << "Students data loaded (or attempted to load) successfully.\n";
}

// Function to save course data to file
void saveCoursesToFile() {
    ofstream outFile(COURSES_FILE);
    if (!outFile.is_open()) {
        cerr << "Error: Could not open courses file for writing.\n";
        return;
    }
    for (const auto& c : courses) {
        outFile << c.courseName << ","
                << fixed << setprecision(2) << c.kcetFees << ","
                << fixed << setprecision(2) << c.managementFees << "\n";
    }
    outFile.close();
    cout << "Courses data saved successfully.\n";
}

// Function to load course data from file with error handling
void loadCoursesFromFile() {
    ifstream inFile(COURSES_FILE);
    if (!inFile.is_open()) {
        cerr << "Warning: Courses file not found or could not be opened. Starting with empty course data.\n";
        return;
    }
    courses.clear(); // Clear existing data

    string line;
    int lineNumber = 0;
    while (getline(inFile, line)) {
        lineNumber++;
        stringstream ss(line);
        string segment;
        Course c;

        try {
            if (!getline(ss, c.courseName, ',')) throw runtime_error("Course name missing");
            
            if (!getline(ss, segment, ',')) throw runtime_error("KCET fees missing");
            c.kcetFees = stod(segment);

            if (!getline(ss, segment)) throw runtime_error("Management fees missing"); // Last segment
            c.managementFees = stod(segment);

            courses.push_back(c);
        } catch (const invalid_argument& e) {
            cerr << "Error parsing courses.txt at line " << lineNumber << ": Invalid number format. " << e.what() << " on segment: \"" << segment << "\". Full line: \"" << line << "\"\n";
        } catch (const out_of_range& e) {
            cerr << "Error parsing courses.txt at line " << lineNumber << ": Numeric value out of range. " << e.what() << " on segment: \"" << segment << "\". Full line: \"" << line << "\"\n";
        } catch (const runtime_error& e) {
            cerr << "Error parsing courses.txt at line " << lineNumber << ": Data missing or malformed. " << e.what() << ". Full line: \"" << line << "\"\n";
        } catch (const exception& e) {
            cerr << "An unexpected error occurred while parsing courses.txt at line " << lineNumber << ": " << e.what() << ". Full line: \"" << line << "\"\n";
        }
    }
    inFile.close();
    cout << "Courses data loaded (or attempted to load) successfully.\n";
}

// Function to add default engineering courses
void initializeDefaultCourses() {
    courses.push_back({"Computer Science Engineering", 150000.0, 250000.0});
    courses.push_back({"Electronics & Communication Engineering", 120000.0, 200000.0});
    courses.push_back({"Mechanical Engineering", 100000.0, 180000.0});
    courses.push_back({"Civil Engineering", 90000.0, 160000.0});
    cout << "Default courses initialized.\n";
}


// Function to generate a unique student ID
string generateStudentID() {
    static int nextID = 1001; // Starting ID
    // Find the maximum existing ID to ensure uniqueness across sessions
    if (!students.empty()) {
        int maxExistingID = 0;
        for (const auto& s : students) {
            // Only try to convert if the ID starts with "SID" and is long enough
            if (s.studentID.length() > 3 && s.studentID.substr(0, 3) == "SID") {
                try {
                    int id = stoi(s.studentID.substr(3)); // Extract numeric part
                    if (id > maxExistingID) {
                        maxExistingID = id;
                    }
                } catch (const invalid_argument& e) {
                    cerr << "Warning: Non-numeric student ID found: " << s.studentID << ". Skipping for max ID calculation.\n";
                } catch (const out_of_range& e) {
                    cerr << "Warning: Student ID out of range: " << s.studentID << ". Skipping for max ID calculation.\n";
                }
            }
        }
        if (maxExistingID >= nextID) {
            nextID = maxExistingID + 1;
        }
    }
    return "SID" + to_string(nextID++);
}

// Function to add a new student
void addStudent() {
    Student s;
    cout << "\n--- Add New Student ---\n";

    s.studentID = generateStudentID(); // Assign unique ID

    cout << "Enter student name: ";
    getline(cin, s.name);
    cout << "Enter phone number: ";
    getline(cin, s.phoneNumber);
    cout << "Enter email: ";
    getline(cin, s.email);
    cout << "Enter address: ";
    getline(cin, s.address);
    cout << "Enter blood group: ";
    getline(cin, s.bloodGroup);

    // Course selection
    if (courses.empty()) {
        cout << "No courses available. Please add courses by modifying 'courses.txt' or ensure it's not empty.\n";
        return;
    }
    displayCourseDetails();
    cout << "Enter the exact course name for admission: ";
    getline(cin, s.admittedCourse);
    bool courseFound = false;
    Course selectedCourse;
    for (const auto& c : courses) {
        if (c.courseName == s.admittedCourse) {
            selectedCourse = c;
            courseFound = true;
            break;
        }
    }
    if (!courseFound) {
        cout << "Error: Course not found. Please enter an exact course name from the list.\n";
        return;
    }

    cout << "Enter admission type (KCET/Management): ";
    getline(cin, s.admissionType);
    while (s.admissionType != "KCET" && s.admissionType != "Management") {
        cout << "Invalid admission type. Please enter 'KCET' or 'Management': ";
        getline(cin, s.admissionType);
    }

    if (s.admissionType == "KCET") {
        s.feesPaid = selectedCourse.kcetFees;
    } else { // Management
        s.feesPaid = selectedCourse.managementFees * (1 - MANAGEMENT_DISCOUNT_PERCENTAGE / 100.0);
    }
    cout << "Calculated Fees: " << fixed << setprecision(2) << s.feesPaid << " INR\n";

    cout << "Enter total marks obtained (out of 500): ";
    while (!(cin >> s.totalMarks) || s.totalMarks < 0 || s.totalMarks > 500) {
        cout << "Invalid marks. Please enter a number between 0 and 500: ";
        cin.clear();
        clearInputBuffer();
    }
    cout << "Enter rank obtained: ";
    while (!(cin >> s.rankObtained) || s.rankObtained <= 0) {
        cout << "Invalid rank. Please enter a positive integer: ";
        cin.clear();
        clearInputBuffer();
    }
    cout << "Enter expected package after graduation (in Lakhs per annum): ";
    while (!(cin >> s.expectedPackage) || s.expectedPackage < 0) {
        cout << "Invalid package. Please enter a non-negative number: ";
        cin.clear();
        clearInputBuffer();
    }
    clearInputBuffer(); // Clear buffer after numeric input

    students.push_back(s);
    cout << "Student record added successfully with ID: " << s.studentID << "!\n";
    saveStudentsToFile(); // Save immediately after adding
}

// Function to display all students
void displayAllStudents() {
    if (students.empty()) {
        cout << "\nNo student records to display.\n";
        return;
    }
    cout << "\n---- All Student Records ------\n";
    for (const auto& s : students) {
        cout << "--------------------------------\n";
        cout << "Student ID: " << s.studentID << endl;
        cout << "Name: " << s.name << endl;
        cout << "Phone: " << s.phoneNumber << endl;
        cout << "Email: " << s.email << endl;
        cout << "Address: " << s.address << endl;
        cout << "Blood Group: " << s.bloodGroup << endl;
        cout << "Course: " << s.admittedCourse << endl;
        cout << "Admission Type: " << s.admissionType << endl;
        cout << "Total Marks: " << fixed << setprecision(2) << s.totalMarks << endl;
        cout << "Rank: " << s.rankObtained << endl;
        cout << "Expected Package: " << fixed << setprecision(2) << s.expectedPackage << " LPA\n";
        cout << "Fees Paid: " << fixed << setprecision(2) << s.feesPaid << " INR\n";
    }
    cout << "--------------------------------\n";
}

// Function to search student by ID
void searchStudentByID() {
    if (students.empty()) {
        cout << "No students to search.\n";
        return;
    }
    string idToSearch;
    cout << "Enter student ID to search (e.g., SID1001): ";
    getline(cin, idToSearch);

    bool found = false;
    for (const auto& s : students) {
        if (s.studentID == idToSearch) {
            cout << "\n--- Student Found ---\n";
            cout << "Student ID: " << s.studentID << endl;
            cout << "Name: " << s.name << endl;
            cout << "Phone: " << s.phoneNumber << endl;
            cout << "Email: " << s.email << endl;
            cout << "Address: " << s.address << endl;
            cout << "Blood Group: " << s.bloodGroup << endl;
            cout << "Course: " << s.admittedCourse << endl;
            cout << "Admission Type: " << s.admissionType << endl;
            cout << "Total Marks: " << fixed << setprecision(2) << s.totalMarks << endl;
            cout << "Rank: " << s.rankObtained << endl;
            cout << "Expected Package: " << fixed << setprecision(2) << s.expectedPackage << " LPA\n";
            cout << "Fees Paid: " << fixed << setprecision(2) << s.feesPaid << " INR\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student with ID " << idToSearch << " not found.\n";
    }
}

// Function to update student details (by ID)
void updateStudentDetails() {
    if (students.empty()) {
        cout << "No students to update.\n";
        return;
    }
    string idToUpdate;
    cout << "Enter student ID to update: ";
    getline(cin, idToUpdate);

    bool found = false;
    for (auto& s : students) { // Use reference to modify
        if (s.studentID == idToUpdate) {
            found = true;
            cout << "\n--- Updating Student (ID: " << s.studentID << ") ---\n";
            cout << "Enter new name (current: " << s.name << "): ";
            getline(cin, s.name);
            cout << "Enter new phone number (current: " << s.phoneNumber << "): ";
            getline(cin, s.phoneNumber);
            cout << "Enter new email (current: " << s.email << "): ";
            getline(cin, s.email);
            cout << "Enter new address (current: " << s.address << "): ";
            getline(cin, s.address);
            cout << "Enter new blood group (current: " << s.bloodGroup << "): ";
            getline(cin, s.bloodGroup);

            // Re-select course and admission type to update fees if needed
            if (courses.empty()) {
                cout << "No courses available to choose from. Course will remain: " << s.admittedCourse << endl;
            } else {
                displayCourseDetails();
                cout << "Enter new course for admission (current: " << s.admittedCourse << "): ";
                string newCourseName;
                getline(cin, newCourseName);
                bool newCourseFound = false;
                Course newSelectedCourse;
                for (const auto& c : courses) {
                    if (c.courseName == newCourseName) {
                        newSelectedCourse = c;
                        newCourseFound = true;
                        break;
                    }
                }
                if (!newCourseFound) {
                    cout << "Error: New course not found. Keeping old course: " << s.admittedCourse << endl;
                } else {
                    s.admittedCourse = newCourseName;
                    cout << "Enter new admission type (KCET/Management) (current: " << s.admissionType << "): ";
                    getline(cin, s.admissionType);
                    while (s.admissionType != "KCET" && s.admissionType != "Management") {
                        cout << "Invalid admission type. Please enter 'KCET' or 'Management': ";
                        getline(cin, s.admissionType);
                    }

                    if (s.admissionType == "KCET") {
                        s.feesPaid = newSelectedCourse.kcetFees;
                    } else { // Management
                        s.feesPaid = newSelectedCourse.managementFees * (1 - MANAGEMENT_DISCOUNT_PERCENTAGE / 100.0);
                    }
                    cout << "New Fees calculated: " << fixed << setprecision(2) << s.feesPaid << " INR\n";
                }
            }

            cout << "Enter new total marks (current: " << fixed << setprecision(2) << s.totalMarks << "): ";
            while (!(cin >> s.totalMarks) || s.totalMarks < 0 || s.totalMarks > 500) {
                cout << "Invalid marks. Please enter a number between 0 and 500: ";
                cin.clear();
                clearInputBuffer();
            }
            cout << "Enter new rank (current: " << s.rankObtained << "): ";
            while (!(cin >> s.rankObtained) || s.rankObtained <= 0) {
                cout << "Invalid rank. Please enter a positive integer: ";
                cin.clear();
                clearInputBuffer();
            }
            cout << "Enter new expected package (current: " << fixed << setprecision(2) << s.expectedPackage << "): ";
            while (!(cin >> s.expectedPackage) || s.expectedPackage < 0) {
                cout << "Invalid package. Please enter a non-negative number: ";
                cin.clear();
                clearInputBuffer();
            }
            clearInputBuffer(); // Clear buffer after numeric input

            cout << "Student details updated successfully!\n";
            saveStudentsToFile(); // Save changes
            break;
        }
    }
    if (!found) {
        cout << "Student with ID " << idToUpdate << " not found.\n";
    }
}

// Function to delete student by ID
void deleteStudentByID() {
    if (students.empty()) {
        cout << "No students to delete.\n";
        return;
    }
    string idToDelete;
    cout << "Enter student ID to delete: ";
    getline(cin, idToDelete);

    // Use a lambda function to find the student by ID
    auto it = remove_if(students.begin(), students.end(),
                        [idToDelete](const Student& s) { return s.studentID == idToDelete; });

    if (it != students.end()) {
        students.erase(it, students.end());
        cout << "Student with ID " << idToDelete << " deleted successfully.\n";
        saveStudentsToFile(); // Save changes
    } else {
        cout << "Student with ID " << idToDelete << " not found.\n";
    }
}

// Function to sort students by rank
void sortStudentsByRank() {
    if (students.empty()) {
        cout << "No students to sort.\n";
        return;
    }
    // Sorts students in ascending order of rank
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.rankObtained < b.rankObtained;
    });
    cout << "Students sorted by rank (ascending).\n";
    displayAllStudents(); // Display sorted list
}

// Function to generate sample students
void generateSampleStudents(int count) {
    if (courses.empty()) {
        cout << "Cannot generate sample students, no courses defined. Please ensure 'courses.txt' has data or default courses are initialized.\n";
        return;
    }
    srand(static_cast<unsigned int>(time(0))); // Seed for random numbers

    string names[] = {"Alice", "Bob", "Charlie", "Diana", "Eve", "Frank", "Grace", "Heidi", "Ivan", "Judy",
                      "Kevin", "Liam", "Mia", "Noah", "Olivia", "Peter", "Quinn", "Rachel", "Sam", "Tina",
                      "Uma", "Victor", "Wendy", "Xavier", "Yara", "Zack", "Anna", "Ben", "Chloe", "David",
                      "Emily", "Fred", "Gina", "Harry", "Iris", "Jack", "Karen", "Leo", "Mona", "Nate"}; // More names
    string bloodGroups[] = {"A+", "B+", "AB+", "O+", "A-", "B-", "AB-", "O-"};

    for (int i = 0; i < count; ++i) {
        Student s;
        s.studentID = generateStudentID();
        s.name = names[i % (sizeof(names) / sizeof(names[0]))] + " " + to_string(100 + rand() % 900); // Add random number for more unique names
        s.phoneNumber = "98" + to_string(10000000 + rand() % 90000000); // Dummy number
        s.email = s.name.substr(0, s.name.find(" ") != string::npos ? s.name.find(" ") : s.name.length()) + to_string(rand() % 1000) + "@example.com";
        s.address = "Street " + to_string(rand() % 100) + ", City " + to_string(rand() % 10) + ", PIN " + to_string(560000 + rand() % 1000);
        s.bloodGroup = bloodGroups[rand() % (sizeof(bloodGroups) / sizeof(bloodGroups[0]))];

        // Randomly assign course
        int courseIndex = rand() % courses.size();
        s.admittedCourse = courses[courseIndex].courseName;

        // Randomly assign admission type
        s.admissionType = (rand() % 2 == 0) ? "KCET" : "Management";

        if (s.admissionType == "KCET") {
            s.feesPaid = courses[courseIndex].kcetFees;
        } else {
            s.feesPaid = courses[courseIndex].managementFees * (1 - MANAGEMENT_DISCOUNT_PERCENTAGE / 100.0);
        }

        s.totalMarks = 300.0 + (rand() % 200) + (rand() % 100 / 100.0); // Marks between 300-499.99
        s.rankObtained = 1 + (rand() % 5000); // Rank between 1-5000
        s.expectedPackage = 3.0 + (rand() % 100) / 10.0; // Package between 3.0 and 12.9 LPA

        students.push_back(s);
    }
    cout << count << " sample students generated.\n";
    saveStudentsToFile();
}

// Function to display course details and fees
void displayCourseDetails() {
    if (courses.empty()) {
        cout << "\nNo engineering courses defined.\n";
        return;
    }
    cout << "\n---- Engineering Courses and Fees ----\n";
    cout << "------------------------------------------------------------------\n";
    cout << left << setw(40) << "Course Name"
         << left << setw(15) << "KCET Fees"
         << left << setw(15) << "Mgmt Fees" << endl;
    cout << "------------------------------------------------------------------\n";
    for (const auto& c : courses) {
        cout << left << setw(40) << c.courseName
             << fixed << setprecision(2) << left << setw(15) << c.kcetFees
             << fixed << setprecision(2) << left << setw(15) << c.managementFees << endl;
    }
    cout << "------------------------------------------------------------------\n";
    cout << "Management admission discount: " << fixed << setprecision(1) << MANAGEMENT_DISCOUNT_PERCENTAGE << "%\n";
    cout << "------------------------------------------------------------------\n";
}

// Function to count admissions by type
void countAdmissionsByType() {
    if (students.empty()) {
        cout << "\nNo student records to count.\n";
        return;
    }
    int kcetCount = 0;
    int managementCount = 0;
    for (const auto& s : students) {
        if (s.admissionType == "KCET") {
            kcetCount++;
        } else if (s.admissionType == "Management") {
            managementCount++;
        }
    }
    cout << "\n--- Admission Statistics ---\n";
    cout << "Total students admitted through KCET: " << kcetCount << endl;
    cout << "Total students admitted through Management: " << managementCount << endl;
    cout << "----------------------------\n";
}