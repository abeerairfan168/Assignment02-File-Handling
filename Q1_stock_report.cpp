// Name:    ABEERA IRFAN
// Reg No:  L1F25BSCS0118
// Assignment: 02
// File Handling - Q1 Stock Report

#include <iostream>
#include <fstream> 
#include <string>
using namespace std;
int main(){
	ifstream infile("stock.txt");
   	if (!infile)
	{
		cout << "error:file did not opened" << endl;
		return 1;
	}
	string header;
	getline(infile, header);
	string productId;
	getline(infile, header);
	string productName;
	int quantity;
	double price;
	double totalValue = 0;
	cout << "___ Stock Report ___" << endl;
	while (infile >> productId >> productName >> quantity >> price) {
		double value = quantity * price;
		totalValue = totalValue + value;
		if (quantity < 10) {
			cout << "LOW STOCK" << endl;

		}
	}
	cout << "Total Stock Value:" << totalValue << endl;
	infile.close();
	return 0;
}
