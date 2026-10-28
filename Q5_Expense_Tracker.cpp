// NAME : ABEERA IRFAN 
//RED NO : L1F25BSCS0118
// Assignment 02
//FILE HANDLING Q5 Expense Tracker
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

int  main5() {
    int choice = 0;

    while (choice != 5) {
        cout << "Expense Tracker" << endl;
        cout << "1: Add an expense" << endl;
        cout << "2: Show all expenses" << endl;
        cout << "3: Show total of a category" << endl;
        cout << "4: Clear all expenses" << endl;
        cout << "5: Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice!" << endl;
            continue;
        }

        if (choice == 1) {
            string category;
            int amount;
            cout << "Enter category: ";
            cin >> category;
            cout << "Enter amount: ";
            if (!(cin >> amount) || amount < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid amount!" << endl;
            }
            else {
                ofstream outFile("expenses.txt", ios::app);
                outFile << category << " << amount "  << "\n";
                    outFile.close();
                cout << "Expense saved." << endl;
            }
        }
        else if (choice == 2) {
            ifstream inFile("expenses.txt");
            if (!inFile) {
                cout << "No expenses yet." << endl;
            }
            else {
                string cat;
                int amt;
                bool hasData = false;
                while (inFile >> cat >> amt) {
                    cout << cat << " << amt " << endl;
                        hasData = true;
                }
                if (!hasData) {
                    cout << "No expenses yet." << endl;
                }
                inFile.close();
            }
        }
        else if (choice == 3) {
            string searchCat;
            cout << "Enter category: ";
            cin >> searchCat;
            ifstream inFile("expenses.txt");
            int total = 0;
            bool found = false;
            string cat;
            int amt;
            while (inFile >> cat >> amt) {
                if (cat == searchCat) {
                    total += amt;
                    found = true;
                }
            }
            inFile.close();
            if (found) {
                cout << "Total for " << searchCat << ": " << total << endl;
            }
            else {
                cout << "No expenses found for " << searchCat << endl;
            }
        }
        else if (choice == 4) {
            ofstream outFile("expenses.txt", ios::trunc);
            outFile.close();
            cout << "All expenses cleared." << endl;
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}