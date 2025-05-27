#include <iostream>
#include <string>
using namespace std;

class MedicalCase {
public:
    string patientName;
    string caseType;

    MedicalCase(string name, string type) : patientName(name), caseType(type) {}

    virtual void registerCase() = 0;
};

class InfectiousDisease : public MedicalCase {
public:
    InfectiousDisease(string name) : MedicalCase(name, "Infectious Disease") {}

    void registerCase() override {
        cout << "Infectious Disease case registered for " << patientName << "." << endl;
        cout << "Action: Isolation and contact tracing initiated." << endl;
    }
};

class EmergencySurgery : public MedicalCase {
public:
    EmergencySurgery(string name) : MedicalCase(name, "Emergency Surgery") {}

    void registerCase() override {
        cout << "Emergency Surgery case registered for " << patientName << "." << endl;
        cout << "Action: Surgical team alerted and operating room prepared." << endl;
    }
};

class ChronicIllness : public MedicalCase {
public:
    ChronicIllness(string name) : MedicalCase(name, "Chronic Illness") {}

    void registerCase() override {
        cout << "Chronic Illness case registered for " << patientName << "." << endl;
        cout << "Action: Long-term care plan developed and specialist consultation scheduled." << endl;
    }
};

int main() {
    MedicalCase* case1 = new InfectiousDisease("Narendra");
    MedicalCase* case2 = new EmergencySurgery("Hey Amith");
    MedicalCase* case3 = new ChronicIllness("Dyamesh");

    cout << "=== Medical Case Registration ===" << endl;
    case1->registerCase();
    cout << endl;
    case2->registerCase();
    cout << endl;
    case3->registerCase();

    delete case1;
    delete case2;
    delete case3;

    return 0;
}
