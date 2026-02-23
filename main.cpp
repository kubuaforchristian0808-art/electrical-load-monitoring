#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
double totalEnergy = 0;

// Appliance Class
class Appliance {
private:
    string name;
    double power;
    double hours;

public:
    Appliance(string n, double p, double h) {
        name = n;
        power = p;
        hours = h;
    }

    double calculateEnergy() {
        double energy = (power * hours) / 1000.0;
        totalEnergy += energy;
        return energy;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Power: " << power << " W" << endl;
        cout << "Usage: " << hours << " hours/day" << endl;
        cout << "Daily Energy: " << calculateEnergy() << " kWh" << endl;
        cout << "----------------------------" << endl;
    }
};

//Gblobal vector to store appliances
vector<Appliance> appliances;

// Function to register appliance
void registerAppliance() {
    string name;
    double power, hours;

    cout << "Enter appliance name: ";
    cin >> name;

    cout << "Enter power rating (W): ";
    cin >> power;

    cout << "Enter usage hours per day: ";
    cin >> hours;

    double energy = (power * hours) / 1000.0;

    totalEnergy += energy;   // ← THIS LINE IS CRITICAL

    cout << "Appliance registered successfully!\n";
}

// Function to view appliances
void viewAppliances() {
    if (appliances.empty()) {
        cout << "No appliances registered.\n";
        return;
    }

    for (int i = 0; i < appliances.size(); i++) {
        appliances[i].display();
    }
}
void saveReportToFile() {
    ofstream file("report.txt");

    file << "Electrical Load Monitoring Report\n";
    file << "Total Energy: " << totalEnergy << " kWh\n";

    file.close();

    cout << "Report saved to report.txt\n";
}
// Main Function
int main() {
    int choice;

    do {
        cout << "\n=== Electrical Load Monitoring System ===\n";
        cout << "1. Register Appliance\n";
        cout << "2. View Appliances\n";
        cout << "3. Display Total Energy\n";
        cout << "4. Calculate Total Cost\n";
        cout << "5. Save Report to File\n";
cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            registerAppliance();
        }
        else if (choice == 2) {
            viewAppliances();
        }
        else if (choice == 3) {
            cout << "\nTotal Daily Energy Consumption: "
                 << totalEnergy << " kWh\n";
        }
        else if (choice == 4) {
            double tariff;
            cout << "Enter electricity tariff per kWh: ";
            cin >> tariff;

            double cost = totalEnergy * tariff;

            cout << "\nTotal Cost: " << cost << endl;
        }
        else if (choice == 5) {
    saveReportToFile();
}
else if (choice == 6) {
    cout << "Exiting program...\n";
}
else {
    cout << "Invalid choice. Try again.\n";
}       

    } while (choice != 6);

    return 0;
}