#include<iostream>
using namespace std;

class Clock {
public:
    int hours, minutes, seconds;

    void setTime(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void showTime() {
        cout << "Current Time: " << hours << ":" << minutes << ":" << seconds << endl;
    }
};

int main() {
    Clock c;
    c.setTime(10, 45, 30);
    c.showTime();
    return 0;
}
