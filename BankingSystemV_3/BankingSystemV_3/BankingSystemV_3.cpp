// BankingSystemV_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
enum { MAKE = 1, DEPOSIT, WITHDRAW, DISPLAYINFO, EXIT}; //menu option
enum { NORMAL = 1, CREDIT}; //type of Account
enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2}; //Credit Level
//class name: Account
class Account 
{
private:
	int accNum;
	int balance;
	string name;
public:
	Account(int accontNumber, string accHolder, int balance);
	int GetAccountNumber();
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccountInfo();
};

Account::Account(int accontNumber, string accHolder, int balance) 
	:accNum(accontNumber), balance(balance)
{
	name = accHolder;
}

int Account::GetAccountNumber() 
{
	return accNum;
}

void Account::Deposit(int money) 
{
	balance += money;
}

int Account::Withdraw(int money) 
{
	if (balance < money) 
	{
		return 0;
	}
	balance -= money;
	return balance;
}

void Account::ShowAccountInfo() 
{
	cout << "Account Number: " << accNum << endl;
	cout << "Account Holder Name: " << name << endl;
	cout << "Balance: " << balance << endl;
}
//end of Class Account

//class Name: NormalAccount
class NormalAccount :public Account
{
private:
	int interestRate;
public:
	NormalAccount(int accountNumber, string accHolder, int balance, int rate);
	virtual void Deposit(int money);
};

NormalAccount::NormalAccount(int accountNumber, string accHolder, int balance, int rate)
	:Account(accountNumber, accHolder, balance), interestRate(rate)
{
	//empty
}
void NormalAccount::Deposit(int money) 
{
	Account::Deposit(money);
	Account::Deposit(money*(interestRate / 100.0));
}
//end of NormalAccount class

//class Name: HighCreditAccount
class HighCreditAccount :public NormalAccount
{
private:
	int creditLevel;
public:
	HighCreditAccount(int accountNumber, string accHodler, int balance, int rate, int special);
	virtual void Deposit(int money);
};

HighCreditAccount::HighCreditAccount(int accountNumber, string accHolder, int balance, int rate, int special) 
	:NormalAccount(accountNumber, accHolder, balance, rate), creditLevel(special)
{
	//empty;
}

void HighCreditAccount::Deposit(int money) 
{
	NormalAccount::Deposit(money);
	NormalAccount::Deposit(money *(creditLevel / 100.0));
}
//end of HighCreditAccount

//Class Name: AccountHandler
class AccountHandler 
{
private:
	Account *accArr[100];
	int numberOfAccount;

public:
	AccountHandler();
	void ShowMenu();
	void CreateAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAccountInformation();
	~AccountHandler();

protected:
	void MakeNormalAccount();
	void MakeCreditAccount();
};

AccountHandler::AccountHandler() 
	:numberOfAccount(0)
{
	//empty;
}
void AccountHandler::ShowMenu() 
{
	cout << "============Menu============" << endl;
	cout << "1: Create Account" << endl;
	cout << "2: Deposit" << endl;
	cout << "3: Withdraw" << endl;
	cout << "4: Display Information" << endl;
	cout << "5: Exit" << endl;
	cout << endl;
}

void AccountHandler::CreateAccount() 
{
	int selection;
	cout << "[Options Types of Account]" << endl;
	cout << "1: Normal Account" << endl;
	cout << "2: High Credit Account" << endl;
	cout << "Select: "; cin >> selection; 
	cout << endl;
	if(selection == NORMAL)
	{
		MakeNormalAccount();
	}
	else 
	{
		MakeCreditAccount();
	}
	cout << endl;
}

void AccountHandler::MakeNormalAccount() 
{
	int accNum;
	int initialBalance;
	string accHolder;
	int interestRate;

	cout << "[Creating Normal Account]" << endl;
	cout << "Account Number: "; cin >> accNum; cout << endl;
	cout << "Account Holder Name: "; cin >> accHolder; cout << endl;
	cout << "Initial Deposit: "; cin >> initialBalance; cout << endl;
	cout << "Interest Rate: "; cin >> interestRate; cout << endl;
	cout << endl;

	accArr[numberOfAccount++] = new NormalAccount(accNum, accHolder, initialBalance, interestRate);
}
//int accountNumber, string accHodler, int balance, int rate, int special
void AccountHandler::MakeCreditAccount() 
{
	int accNum;
	string accHolder;
	int initialBalance;
	int interestRate;
	int creditLevel;

	cout << "[Creating Credit Account]" << endl;
	cout << "Account Number: "; cin >> accNum; cout << endl;
	cout << "Account Holder Name: "; cin >> accHolder; cout << endl;
	cout << "Initial Deposit "; cin >> initialBalance; cout << endl;
	cout << "Interest Rate: "; cin >> interestRate; cout << endl;
	cout << "Credit Leve: 1 To A , 2 To B, 3 To C "; cin >> creditLevel; cout << endl;

	cout << endl;
	switch (creditLevel) 
	{
	case 1:
		accArr[numberOfAccount++] = new HighCreditAccount(accNum, accHolder, initialBalance, interestRate, LEVEL_A);
		break;

	case 2:
		accArr[numberOfAccount++] = new HighCreditAccount(accNum, accHolder, initialBalance, interestRate, LEVEL_B);
		break;

	case 3:
		accArr[numberOfAccount++] = new HighCreditAccount(accNum, accHolder, initialBalance, interestRate, LEVEL_C);
		break;
	}
}

void AccountHandler::DepositMoney() 
{
	int accNum;
	int money;
	cout << "[Deposit]" << endl;
	cout << "Enter Account Number: "; cin >> accNum; cout << endl;
	cout << "Enter Money to Deposit: "; cin >> money; cout << endl;

	for (int i = 0; i < numberOfAccount; i++) 
	{
		if (accArr[i]->GetAccountNumber() == accNum) 
		{
			cout << "Successfully Accessed" << endl;
			accArr[i]->Deposit(money);
			cout << "Successfully Deposited" << endl;
		}
		cout << "Fail to Access" << endl;
	}
	cout << endl;
}

void AccountHandler::WithdrawMoney() 
{
	int accNum;
	int money;
	cout << "[Withdraw]" << endl;
	cout << "Enter Account Number: "; cin >> accNum; cout << endl;
	cout << "Enter Money to Withdraw: "; cin >> money; cout << endl;

	for (int i = 0; i < numberOfAccount; i++) 
	{
		if (accArr[i]->GetAccountNumber() == accNum) 
		{
			if (accArr[i]->Withdraw(money) <= 0) 
			{
				cout << "Not Enough Budget" << endl;
			}

			accArr[i]->Withdraw(money);
		}
		cout << "Fail to Access" << endl;
	}
	cout << endl;
}

void AccountHandler::ShowAccountInformation() 
{
	for (int i = 0; i < numberOfAccount; i++) 
	{
		accArr[i]->ShowAccountInfo();
	}
	cout << endl;
}

AccountHandler::~AccountHandler() 
{
	for (int i = 0; i < numberOfAccount; i++) 
	{
		delete accArr[i];
	}
}
int main()
{
	int choice;
	AccountHandler manager;
	while (true) 
	{
		manager.ShowMenu();
		cout << "Select "; cin >> choice;

		switch (choice) 
		{
		case MAKE:
			manager.CreateAccount();
			break;

		case DEPOSIT:
			manager.DepositMoney();
			break;

		case WITHDRAW:
			manager.WithdrawMoney();
			break;

		case DISPLAYINFO:
			manager.ShowAccountInformation();
			break;

		case EXIT:
			return 0;

		default:
			cout << "Illegal Selection" << endl;
		}
	}
	return 0;
}
//enum { MAKE = 1, DePOSIT, WITHDRAW, DISPLAYINFO, EXIT};
