// Name:    Abeera irfan
// Reg No:  L1F25BSCS0118
// Assignment: 02
// File Handling - Q3 student records
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    double cgpa;
};
int main3() {
    ifstream inFile("class1.txt");
    if (!inFile) {
        cout << "Error: class1.txt nahi mili!" << endl;
        return 1;
    }

    vector<Student> students;
    string name;
    double cgpa;
    while (inFile >> name >> cgpa) {
        students.push_back({ name, cgpa });
    }
    inFile.close();

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.cgpa > b.cgpa;
        });

    cout << "Sorted Students by CGPA:" << endl;
    for (auto& st : students) {
        cout << st.name << " - " << fixed << setprecision(2) << st.cgpa << endl;
    }

    if (!students.empty()) {
        Student top = students[0]; cout << "Highest CGPA: " << top.name << " - " << fixed << setprecision(2) << top.cgpa << endl;
    }

    ofstream outFile("scholarship.txt");
    if (outFile) {
        for (auto& st : students) {s
        }
        outFile.close();
        cout << "Output file ban gayi: scholarship.txt" << endl;
    }

    return 0;
}
