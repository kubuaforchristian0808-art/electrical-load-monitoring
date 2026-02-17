#include <iostream>
#include <string>
using namespace std;

class Appliance {
private:
    string name;
    double powerRating;  // in watts
    double usageHours;   // per day

public:
    void setAppliance(string n, double p, double u) {
        name = n;
        powerRating = p;
        usageHours = u;
    }

    string getName() {
        return name;
    }

    double calculateEnergy() {
        return (powerRating * usageHours) / 1000; // kWh
    }

    void display() {
        cout << "Appliance: " << name << endl;
        cout << "Power Rating: " << powerRating << " W" << endl;
        cout << "Daily Usage: " << usageHours << " hours" << endl;
        cout << "Daily Energy Consumption: "
             << calculateEnergy() << " kWh" << endl;
    }
};

int main() {
    cout << "Electrical Load Monitoring System" << endl;
    return 0;
}
