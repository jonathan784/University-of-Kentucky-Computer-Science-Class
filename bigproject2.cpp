//--------------------------------------------------------------------------------
//                         CS 215 07 - project 2
// Jonathan Jimenez
// 03/18/18
// ATM
//---------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
const int MAX_ACCOUNTS = 100, INVALID_ACCT_PIN = -1, SHUT_DOWN = -2, MAX_TRANS = 5, READ_ERROR = -1; 
int readAccts(string acctNumber[], int acctPin[], double acctBalance[]) {
	int accts;
	ifstream f;
	f.open("accounts.txt");
	f >> accts;
	if (!f.fail()) {
		for (int i = 0; i < accts; i++) {					
			f >> acctNumber[i] >> acctPin[i] >> acctBalance[i];
		}
		return accts;
	}
	else {
		return -1;
	}
}
void printAccts(string acctNumber[], int acctPin[], double acctBalance[], int numberAccts) {
	cout << "Current Accounts: number = " << numberAccts << endl;
	cout << "ACCOUNT       PIN   BALANCE\n";
	cout << "------------  ----  ---------" << endl;
	for (int i = 0; i < numberAccts; i++) {
		cout << setfill(' ') << setw(12) << left << acctNumber[i] << "  " << acctPin[i] << "  $" << right << setw(8) << acctBalance[i] << endl;
	}
}
bool startup(string acctNumber[], int acctPin[], double acctBalance[]) {
	cout << "-------------------------------------------------------------------------------" << endl;
		cout << "                       WILDCAT BANKING ATM"<< endl;
		cout << "                       By: Jonathan Jimenez" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "ATM STARTUP...\n";
	int accts = readAccts(acctNumber, acctPin, acctBalance);
	if (accts == READ_ERROR) {					
		cout << "Error reading accounts!\n";	
		return true;
	}
	else {
		printAccts(acctNumber, acctPin, acctBalance, accts);
		return false;
	}
}
int custLogin(string acctNumber[], int acctPin[], double acctBalance[]) {
	string userAcct; 
	int userPin; 
	int postion = INVALID_ACCT_PIN;
	cout << "Enter account number:\t";
	cin >> userAcct;
	cout << "Enter pin number:\t";
	cin >> userPin;
	if (userAcct == "10000" && userPin == 1000) {
		return SHUT_DOWN;
	}
	else {
		for (int i = 0; i < MAX_ACCOUNTS; i++) {
			if (userAcct == acctNumber[i]) {
				postion = i;
			}									 
		}
		if (postion != -1) {
			if (userPin == acctPin[postion]) {
				return postion;
			}
		}
	}
	cout << "Invalid account/pin combination.\n" << endl; 
	return postion;
}
char askAction() {
	string action;
	int i = 0;
	do {
		cout << "W - Withdraw\n"
			<< "D - Deposit\n"
			<< "B - Get Current Balance\n"
			<< "Enter transaction code: ";
		cin >> action;
		char hold = toupper(action[0]);
		switch (hold) {
		case 'W': return 'W'; break;
		case 'D': return 'D'; break;		
		case 'B': return 'B'; break;
		default: cout << "Invalid option...please enter W, D, or B!\n";
		}
	} while (i != 1);
}
void addTransactions(string acctNumber[], string trasactionAcct[], double tranBalance[], double acctBalance[], int numberAccts, int & transactionCount, double amount, int sign) {
	if (transactionCount <= MAX_TRANS) {
		cout << "Transaction complete.\n"
			<< "Your new balance is $" << ((acctBalance[numberAccts]) + (sign*amount)) << endl; 
		acctBalance[numberAccts] += (sign*amount);
		trasactionAcct[transactionCount] = acctNumber[numberAccts];		
		tranBalance[transactionCount] = acctBalance[numberAccts];		
		transactionCount++;
	}
	else {
		cout << "Transaction cannot be done. Contact IT Support\n";
	}
}
void doWithdraw(string acctNumber[], string trasactionAcct[], double tranBalance[], double acctBalance[], int numberAccts, int & transactionCount) {
	double withDrawl;
	cout << "Enter withdraw amount: $";
	cin >> withDrawl;
	int checker = 1;
	while (withDrawl > acctBalance[numberAccts] || withDrawl < 0.00) {
		if (withDrawl < 0.00) {
			cout << "Invalid amount! Enter a value 0.00 or greater.\n";
		}
		else if (withDrawl > acctBalance[numberAccts]) {
			cout << "Your account only has $" << acctBalance[numberAccts] << endl;
		}
		cout << "Enter withdraw amount: $";
		cin >> withDrawl;
	}
	if (withDrawl == 0.00) {
		cout << "Transaction cancelled.\n";
	}
	else {
		addTransactions(acctNumber, trasactionAcct, tranBalance, acctBalance, numberAccts, transactionCount, withDrawl, -1);
	}

}
void doDeposit(string acctNumber[], string trasactionAcct[], double tranBalance[], double acctBalance[], int numberAccts, int & transactionCount) {
	double deposit;
	cout << "Enter deposit amount: $";
	cin >> deposit;
	while (deposit < 0.00) {
		cout << "Invalid amount! Enter a value 0.00 or greater.\n"; 
		cout << "Enter withdraw amount: $";
		cin >> deposit;
	}
	if (deposit == 0.00) {
		cout << "Transaction cancelled.\n";
	}
	else {
		addTransactions(acctNumber, trasactionAcct, tranBalance, acctBalance, numberAccts, transactionCount, deposit, 1); 
	}
}
bool processCust(string acctNumber[], string trasactionAcct[], int acctPin[], double tranBalance[], double acctBalance[], int & numberAccts, int & transactionCount) {
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "                       WILDCAT BANKING ATM" << endl;
	cout << "                       By: Jonathan Jimenez" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	int AcctHolder = custLogin(acctNumber, acctPin, acctBalance);
	while (AcctHolder == SHUT_DOWN || AcctHolder == INVALID_ACCT_PIN) {
		if (AcctHolder == SHUT_DOWN) {
			return true;
		}
		else {
			cout << "-------------------------------------------------------------------------------" << endl;
			cout << "                       WILDCAT BANKING ATM" << endl;
			cout << "                       By: Jonathan Jimenez" << endl;
			cout << "-------------------------------------------------------------------------------" << endl;
			AcctHolder = custLogin(acctNumber, acctPin, acctBalance);
		}
	}
	switch (askAction()) {
	case 'W': doWithdraw(acctNumber, trasactionAcct, tranBalance, acctBalance, AcctHolder, transactionCount); break; 
	case 'D': doDeposit(acctNumber, trasactionAcct, tranBalance, acctBalance, AcctHolder, transactionCount); break;
	case 'B': cout << "Your current balance is $" << acctBalance[AcctHolder] << endl;
	}
	return false;
}
void printTrans(string trasactionAcct[], double tranBalance[], int transactionCount) {
	cout << "Transactions: number = " << transactionCount << endl
		<< "ACCOUNTS      AMOUNT\n"
		<< "------------  ---------\n";
	for (int i = 0; i < transactionCount; i++) {
		cout << setfill(' ') << left << setw(12) << trasactionAcct[i] << "  $" << right << setw(8)
			<< fixed << setprecision(2) << tranBalance[i] << endl; 
	}
}
void writeTrans(string trasactionAcct[], double tranBalance[], int transactionCount) {
	ofstream f;
	f.open("atransactions.txt");
	if (!f.fail()) {
		f << transactionCount << endl;
		for (int i = 0; i < transactionCount; i++) {
			f << trasactionAcct[i] << "   " << tranBalance[i] << endl;
		}
		cout << "Transactions written to file.\n\n";
	}
	else {
		cout << "unable to open output file.\n";
	}
}
void shutdown(string acctNumber[], string trasactionAcct[], int acctPin[], double acctBalance[], double tranBalance[], int  numberAccts, int transactionCount) {
	cout << "Shutting down ATM...\n";
	printTrans(trasactionAcct, tranBalance, transactionCount);
	writeTrans(trasactionAcct, tranBalance, transactionCount); 
	printAccts(acctNumber, acctPin, acctBalance, numberAccts);
	cout << "Shut down complete.\n";
}
int main() {
	string acctNumber[MAX_ACCOUNTS]; int acctPin[MAX_ACCOUNTS];  double acctBalance[MAX_ACCOUNTS];
	string trasactionAcct[MAX_TRANS]; double tranBalance[MAX_TRANS]; int numberAccts = 0; int transactions = 0;
	bool stop;
	if (startup(acctNumber, acctPin, acctBalance) == false) {
		do {
			stop = processCust(acctNumber, trasactionAcct, acctPin, tranBalance, acctBalance, numberAccts, transactions); 
		} while (stop != true);
	}
	shutdown(acctNumber, trasactionAcct, acctPin, acctBalance, tranBalance, numberAccts, transactions);

																	
	system("Pause");
	return 0;
}


