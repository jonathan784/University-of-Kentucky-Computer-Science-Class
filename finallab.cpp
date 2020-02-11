//-------------------------------------------------------
// CS 215 - Lab Exam 1 – 007
// Jonathan Jimenez
//-------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main() {
	double coinnum, num, numbers, i, temp;
	string Penny, Nickel, Dime, Quarter, Half_Dollar;

		cout << "\nQuestion 1:\n";

	cout << "Enter Coin Value (1,5,10,25,50): " ;
	cin >> coinnum;
	while (coinnum != 1 && coinnum != 5 && coinnum != 10 && coinnum != 25 && coinnum != 50) {
		cout << "Invalid Entry" << endl;
		cout << "Enter Coin Value (1,5,10,25,50)";
		cin >> coinnum;

	}
	if (coinnum == 1) {
		cout << "penny";
	}
	else if (coinnum == 5) {
		cout << "Nickel";
	}
	else if (coinnum == 10) {
		cout << "Dime";
	}
	else if (coinnum == 25) {
		cout << "Quarter";
	}
	else if (coinnum == 50) {
		cout << "Half Dollar";
	}

	cout << "\nQuestion 2:\n";
	cout << "How many numbers? (2-10): ";
		cin >> num;

	for (int i = 1; i <= num; i++) {
		cout << "Enter Score " << i << ": ";
		cin >> numbers;
	}
	int count = 0;
	int count1 = 0;
	int count2 = 0;
	double sum = 0;
	cout << "\nQuestion 3:\n";
	for (int i = 0; i <= 8; i++) {
		cout << "Enter temp " << i << ": ";
		cin >> temp;
		if (temp > 212) {
			count++;
		}
		if (temp < 32) {
			count1++;
		}
		if (temp >= 32 && temp <= 212) {
			count2++;
		}
	}
	cout << "Boiling " << count;
	cout << "Freezing " << count1;
	cout << "Liquid " << count2;

	cout << "\nQuestion 4:\n";
	




	system("pause");
	return 0;
}
