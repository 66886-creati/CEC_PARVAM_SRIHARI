#include<iostream>
#include<fstream>

int main(){
    std::ofstream outfile("example.txt");
    if (outfile.is_open())
    {
        outfile << "Hello, File Handling!";
        outfile.close();
        std::cout << "Data written to file successfully.\n";
    }
    else{
        std::cout << "Unable to open file for writting.\n";
    }
    return 0;
}
