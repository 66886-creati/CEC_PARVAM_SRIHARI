#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

string GetCurrenttime()
{
    time_t now=time(0);
    char *dt=ctime(&now);
    string timestr(dt);
    timestr.pop_back();
    return timestr;
}

void writelog(int userid,const string &action){
    ofstream outfile("log.txt", ios::app);
    if (!outfile)
    {
        cerr << "Error: could not open log.txt for writing.\n";
        return ;
    }

    outfile << "[UserID: " << userid << "] " << action << " at " <<GetCurrenttime << endl;
    outfile.close();
    cout << "Log written successfully.\n";


}

void readlogs()
{
    ifstream infile("log.txt");
    if (!infile)
    {
        cerr << "Error: could not open log.txt for reading.\n";
        return ;

    }
    cout << "\n---- Log file contents ----\n";
    string line;
    while (getline(infile,line))
    {
        cout << line << endl;
    }
    infile.close();
}

void clearlogs(){
    ofstream outfile("log.txt", ios::trunc);
    if (!outfile)
    {
        cerr << "Error: could not open log.txt for clear.\n";
        return;
    }

    outfile.close();
    cout << "All logs have been cleared.\n";
}

int main(){
    int choice,userid;
    string action;

    do
    {
        cout << "\n===== Log management Menu =====\n";
        cout << "1. write a Log\n";
        cout << "2. View all Logs\n";
        cout << "3. Clear log file\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter user ID: ";
            cin >> userid;
            cin.ignore();
            cout << "Enter action (e.g., Logged In, Viewed page): ";
            getline(cin,action);
            writelog(userid,action);
            break;
        case 2:
            readlogs();
            break;
        case 3:
            clearlogs();
            break;
        case 4:
            cout << "3. Clear log file\n";
            break;
        default:
            cout << "Invalid choice, Please try again.\n";
        }
        
       
    } while (choice !=4);

    return 0;
    
}