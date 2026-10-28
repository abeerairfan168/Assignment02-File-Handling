// NAME : ABEERA IRFAN 
//RED NO : L1F25BSCS0118
// Assignment 02
//FILE HANDLING Q4 HEART RATE CLEANER
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main4() {
    ifstream inFile("heart_rate.txt");
    if (!inFile) {
        cout << "heart_rate.txt not found!" << endl;
        return 1;
    }

    int rate[100];
    int count = 0;
    int bad = 0;
    int x;
    char junk[50];
    int reason = 0; // 1 = sentinel, 2 = end of file, 3 = array full

    while (true) {
        if (count >= 100) {
            reason = 3;
            break;
        }
        if (inFile >> x) {
            if (x == -1) {
                reason = 1;
                break;
            }
            rate[count] = x;
            count++;
        }
        else if (inFile.eof()) {
            reason = 2;
            break;
        }
        else {
            inFile.clear();
            inFile >> junk;
            bad++;
        }
    }
    inFile.close();

    // TODO 1: Write every valid reading to clean_heart_rate.txt
    ofstream outFile("clean_heart_rate.txt");
    for (int i = 0; i < count; i++) {
        outFile << rate[i] << "\n";
    }
    outFile.close();

    // TODO 2
    cout << "Valid readings: " << count << endl;
    cout << "Junk skipped: " << bad << endl;

    // TODO 3
    if (count == 0) {
        cout << "No valid readings" << endl;
    }
    else {
        int sum = 0;
        int highest = rate[0];
        for (int i = 0; i < count; i++) {
            sum += rate[i];
            if (rate[i] > highest) highest = rate[i];
        }
        double average = (double)sum / count;
        int aboveAvg = 0;
        int alerts = 0;
        for (int i = 0; i < count; i++) {
            if (rate[i] > average) aboveAvg++;
            if (rate[i] > 100) alerts++;
        }
        cout << "Average: " << average << endl;
        cout << "Highest: " << highest << endl;
        cout << "Above average: " << aboveAvg << endl;
        cout << "Alerts (above 100): " << alerts << endl;
    }

    // TODO 4
    cout << "Stopped because: ";
    if (reason == 1) cout << "sentinel found";
    else if (reason == 2) cout << "end of file";
    else if (reason == 3) cout << "array full";
    cout << endl;

    return 0;
}