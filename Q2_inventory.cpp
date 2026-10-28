// Name:    ABEERA IRFAN
// Reg No:  L1F25BSCS0118
// Assignment: 02
// File Handling - Q2 inventory report

#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

int timeToMinutes(string t) {
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    return h * 60 + m;
}

int main2() {
    ifstream inFile("parking.txt");
    if (!inFile) {
        cout << "parking.txt not found" << endl;
        return 0;
    }

    string date;
    getline(inFile, date);

    string header;
    getline(inFile, header);

    ofstream outFile("receipts.txt");

    string plate;
    char type;
    string inTime, outTime;

    int totalVehicles = 0;
    int totalCollection = 0;
    int longestMinutes = -1;
    string longestPlate;

    outFile << "Receipts for " << date << endl;

    cout << "--- Parking Report for " << date << " ---" << endl;

    while (inFile >> plate >> type >> inTime >> outTime) {
        int inMin = timeToMinutes(inTime);
        int outMin = timeToMinutes(outTime);
        int parked = outMin - inMin;

        int H = parked / 60;
        int M = parked % 60;

        int hoursCharged = (parked + 59) / 60;

        int rate = (type == 'C' || type == 'c') ? 100 : 50;
        int fee = hoursCharged * rate;

        totalVehicles++;
        totalCollection += fee;

        if (parked > longestMinutes) {
            longestMinutes = parked;
            longestPlate = plate;
        }

        string typeStr = (type == 'C' || type == 'c') ? "Car" : "Bike";
        cout << plate << " << typeStr << " << H << " H " << M << " min Fee: " << fee << endl;
        outFile << plate << " << fee " << endl;
    }

    if (totalVehicles == 0) {
        cout << "no vehicles found" << endl;
        outFile.close();
        return 0;
    }

    int longestH = longestMinutes / 60;
    int longestM = longestMinutes % 60;
    double avg = (double)totalCollection / totalVehicles;

    cout << "Total vehicles: " << totalVehicles << endl;
    cout << "Total collection: " << totalCollection << endl;
    cout << "Average fee: " << avg << endl;
    cout << "Longest stay: " << longestPlate << " (" << longestH << " H " << longestM << " min)" << endl;

    inFile.close();
    outFile.close();
    return 0;
}
