#include <iostream>
#include <string>
using namespace std;

// Structure to represent a hospital bed
struct Bed {
    int bedID;
    int bedNumber;
    bool isOccupied;
};

// Function to display bed details
void displayBeds(Bed* beds, int size) {
    cout << "Bed ID | Bed Number | Status" << endl;
    for (int i = 0; i < size; i++) {
        cout << beds[i].bedID << "      | " << beds[i].bedNumber << "          | "
             << (beds[i].isOccupied ? "Occupied" : "Available") << endl;
    }
}

// Function to update bed status
void updateBedStatus(Bed* beds, int bedID, bool status) {
    for (int i = 0; i < 5; i++) {
        if (beds[i].bedID == bedID) {
            beds[i].isOccupied = status;
            cout << "Bed ID " << bedID << " status updated to "
                 << (status ? "Occupied" : "Available") << endl;
            return;
        }
    }
    cout << "Bed ID " << bedID << " not found!" << endl;
}

int main() {
    // Initializing bed details
    Bed beds[5] = {
        {101, 1, false},
        {102, 2, false},
        {103, 3, true},
        {104, 4, false},
        {105, 5, true}
    };

    // Displaying initial bed details
    displayBeds(beds, 5);

    // Updating bed status
    updateBedStatus(beds, 102, true); // Marking bed 102 as occupied

    // Displaying updated bed details
    cout << "\nUpdated Bed Status:" << endl;
    displayBeds(beds, 5);

    return 0;
}
