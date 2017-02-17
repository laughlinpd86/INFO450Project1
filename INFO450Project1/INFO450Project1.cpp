// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>;
#include <iomanip>;


using namespace std;

float InitBalance;
float Balance;
float WithdrawlAMT;
float ChecksAMT;
float DepositAMT;
char input;
char x;

void Instructions();
void SetBalance();
void ViewBalance();
void Deposit();
void Withdrawl();
void Checks();
void FinalBalance();
void Menu();


int main()
{
	Instructions();
	SetBalance();
	ViewBalance();

	do
	{
		Menu();
		switch (input)
		{
		case 'w':
		case 'W':
			Withdrawl();
			break;
		case 'd':
		case 'D':
			Deposit();
			break;
		case 'c':
		case 'C':
			Checks();
			break;
		case 'q':
		case 'Q':
			x = 'q';
			break;
		default:
			cout << "Invalid Entry" << endl;
			break;
		}
	} while (x != 'q');
	FinalBalance();

	system("PAUSE");
	return 0;
}

void Instructions()
{
	cout << "This application is an ATM program which the user input a balance, " << endl;
	cout << "then allows the user to make deposits or withdrawls from the initial balance." << endl;
	cout << "Once the transactions are complete, a final balance will then be displayed\nto the user" << endl;
	system("PAUSE");
}

void SetBalance()
{
	bool valid = false;

	while (!valid)
	{
		valid = true;

		system("CLS");
		cout << "Please enter a starting balance" << endl;
		cin >> InitBalance;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "wrong data type" << endl;
			valid = false;
			system("PAUSE");
		}
	}
	Balance = InitBalance;
}
void ViewBalance()
{
	system("CLS");
	cout << "The Current Balance is" << endl;
	cout << Balance << endl;
}
void Deposit()
{
	bool valid = false;
	float Dep;

	while (!valid)
	{
		valid = true;

		cout << "enter amount for deposit" << endl;
		cin >> Dep;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Error: Wrong data type" << endl;
			valid = false;
			system("PAUSE");
		}
	}
	DepositAMT = DepositAMT + Dep;

}
void Withdrawl()
{
	bool valid = false;
	float With;

	while (!valid)
	{
		valid = true;

		cout << "enter amount for withdrawl" << endl;
		cin >> With;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Error: Wrong data type" << endl;
			valid = false;
			system("PAUSE");
		}
	}
	WithdrawlAMT = WithdrawlAMT + With;
}
void Checks()
{
	bool valid = false;
	float Check;

	while (!valid)
	{
		valid = true;

		cout << "Enter check amount" << endl;
		cin >> Check;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Error: Wrong data type" << endl;
			valid = false;
			system("PAUSE");
		}
	}
	ChecksAMT = ChecksAMT + Check;
}
void FinalBalance()
{
	cout << fixed << setprecision(2);
	cout << "Transaction Summary:" << endl;
	cout << "---------------------------------" << endl;
	cout << "Beginning Balance:          ";
	cout << InitBalance;
	cout << "\nWithdrawls:                 ";
	cout << WithdrawlAMT;
	cout << "\nDeposits:                   ";
	cout << DepositAMT;
	cout << "\nChecks:                     ";
	cout << ChecksAMT;
	cout << endl;
	cout << "---------------------------------" << endl;
	cout << "Ending Value:               ";

	Balance = InitBalance + DepositAMT - WithdrawlAMT - ChecksAMT;
	cout << Balance;
	cout << endl;

}
void Menu()
{
	cout << "(W)ithdrawl, (D)eposit, (C)hecks, (Q)uit" << endl;
	cin >> input;
}