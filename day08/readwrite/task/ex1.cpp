#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>


struct Student {
    std::string name;
    int age;
    char grade;
};


void logActivity(const std::string &activity, const std::string &filename) {
    std::ofstream outfile(filename, std::ios::app);
    if (outfile.is_open()) {
        std::time_t now = std::time(nullptr);
        std::tm *ltm = std::localtime(&now);
        std::ostringstream oss;
        oss << std::put_time(ltm, "%Y-%m-%d %H:%M:%S");
        outfile << "[" << oss.str() << "] " << activity << "\n";
        outfile.close();
        std::cout << "Activity logged.\n";
    } else {
        std::cout << "Unable to open log file.\n";
    }
}


void logStudentRecord(const Student &student, const std::string &filename) {
    std::ostringstream ss;
    ss << "Student Record - Name: " << student.name
       << ", Age: " << student.age
       << ", Grade: " << student.grade;
    logActivity(ss.str(), filename);
}


void readLog(const std::string &filename) {
    std::ifstream infile(filename);
    if (infile.is_open()) {
        std::string line;
        std::cout << "\nActivity log contents:\n";
        while (std::getline(infile, line)) {
            std::cout << line << "\n";
        }
        infile.close();
    } else {
        std::cout << "Unable to open log file.\n";
    }
}

int main() {
    std::string filename = "Activity.log";

   
    logActivity("User logged in", filename);

    
    Student s1{"Alice", 20, 'A'};
    Student s2{"Bob", 19, 'B'};
    logStudentRecord(s1, filename);
    logStudentRecord(s2, filename);


    Student s3;
    std::cout << "\nEnter new student details:\n";
    std::cout << "Name: ";
    std::getline(std::cin, s3.name);
    std::cout << "Age: ";
    std::cin >> s3.age;
    std::cout << "Grade: ";
    std::cin >> s3.grade;
    std::cin.ignore();
    logStudentRecord(s3, filename);

    
    readLog(filename);

    return 0;
}
