#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>

void logActivity(const std::string &activity , const std::string &filename)
{
    std::ofstream outfile(filename,std::ios::app);
    if (outfile.is_open())
    {
        std::time_t now=std::time(nullptr);
        char *dt=std::ctime(&now);
        dt[strcspn(dt, "\n")]='\0';
        outfile << "[" << dt << "]" << activity << "\n";
        outfile.close();
        std::cout << "Activity logged. \n";

    }
    else{
        std::cout << "Unable to open log file. \n";
    }
}

void readLog(const std::string &filename){
    std::ifstream infile(filename);
    if (infile.is_open())
    {
        std::string line;
        std::cout << "Activity logged. \n";
        while (std::getline(infile,line))
        {
            std::cout <<line << "\n";
        }
        infile.close();
    }
    else{
        std::cout << "Unable to open log file. \n";
    }
}

int main(){
    std::string filename="Activity.log";
    logActivity("User logged in", filename);
    logActivity("User performed an action", filename);
    readLog(filename);

    return 0;
}