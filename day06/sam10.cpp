#include <iostream>
#include <string>
using namespace std;

class Booking
{
    public:
        string CustomerName;
        int seats;

        Booking(string name = "", int s=1): CustomerName(name), seats(s) {}

        virtual void bookTicket()=0;

        virtual ~Booking() {}
};

class FlightBooking : public Booking{
    public:
        FlightBooking(string name,int s) : Booking(name, s) {}

        void bookTicket() override
        {
            cout << "Flight Ticket booked for " << CustomerName << "with" << seats << " seat(s)." << endl;
        }
};
class TrainBooking : public Booking{
    public:
        TrainBooking(string name,int s) : Booking(name, s) {}

        void bookTicket() override
        {
            cout << "Train Ticket booked for " << CustomerName << "with" << seats << " seat(s)." << endl;
        }
};
class BusBooking : public Booking{
    public:
        BusBooking(string name,int s) : Booking(name, s) {}

        void bookTicket() override
        {
            cout << "Bus Ticket booked for " << CustomerName << "with" << seats << " seat(s)." << endl;
        }
};

class BookingManager{
    public:
        void confirmBooking(string name){
            cout << "Booking confirmed for: " << name << endl;
        }
        void confirmBooking(string name, int s){
            cout << "Booking confirmed for: " << name << " with " << s << " seat(s). " << endl;
        }

        void confirmBooking(string name, int s,string date){
            cout << "Booking confirmed for: " << name 
                 << " | Seats:  " << s 
                 << " | Date:  " << date << endl;   
        }
};

class GroupBooking
{
    public:
        int totalseats;
        GroupBooking(int seats = 0) : totalseats (seats) {}

        GroupBooking operator+(const GroupBooking &other)
        {
            return GroupBooking(this->totalseats + other.totalseats);

        }

        void display(){
            cout << "Total group seats booked: " << totalseats << endl;
        }
};

int main(){
    Booking *booking1 = new FlightBooking("Rahul", 2);
    Booking *booking2 = new TrainBooking("Ramesh", 3);
    Booking *booking3 = new BusBooking("Vishnu", 2);

    cout << "=== Runtime Polymerphism ===" << endl;
    booking1->bookTicket();
    booking2->bookTicket();
    booking3->bookTicket();

    cout << "\n=== Function Overloading ===" << endl;
    BookingManager manager;
    manager.confirmBooking("David");
    manager.confirmBooking("ANA DE ARMAS" ,4);
    manager.confirmBooking("Johnny",5, "26-07-2006");

    cout << "\n=== Operator Overloading ===" << endl;
    GroupBooking group1(4);
    GroupBooking group2(6);
    GroupBooking totalGroup = group1 + group2;
    totalGroup.display();

    delete booking1;
    delete booking2;
    delete booking3;

    return 0;
}