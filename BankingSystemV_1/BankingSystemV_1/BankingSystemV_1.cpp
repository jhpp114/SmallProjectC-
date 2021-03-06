// BankingSystemV_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>


void ShowMenu(); //printing menu
void MakeAccout(); //create account
void DepositMoney(); //Deposit money
void WithdrawMoney(); //Withdraw Money
void ShowAllAccInfo(); //Display Account Information
void ExitTheProgram();

enum {MAKE =1, DEPOSIT, WITHDRAW, DISPLAYINFO, EXIT}; //made Enum for switch statement

class Account 
{
private:
	int accID;
	int balance;
	std::string name;

public:
	Account(int idNumber, int initialBalance, std::string accName);
	int GetAccNumber();
	void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo();
};

Account::Account(int idNumber, int initialBalance, std::string accName)
	:accID(idNumber), balance(initialBalance)
{
	name = accName;
}

int Account::GetAccNumber() 
{
	return accID;
}

void Account::Deposit(int money) 
{
	balance += money;
}

int Account::Withdraw(int money) 
{
	if (balance < money) 
	{
		std::cout << "Sorry Out of Money!" << std::endl;
		return 0;
	}
	balance -= money;
	return balance;
}

void Account::ShowAccInfo() 
{
	std::cout << "Account ID: " << accID << std::endl;
	std::cout << "Balance: " << balance << std::endl;
	std::cout << "Account Holder Name: " << name << std::endl;
}

Account *accArr[100]; //able to hold 100 of accounts
int accNum = 0; //account starts from 0

int main()
{
	//{MAKE =1, DEPOSIT, WITHDRAW, DISPLAYINFO, EXIT};
	int choice;
	while (true) 
	{
		ShowMenu();
		std::cout << "Select: "; std::cin >> choice; std::cout << std::endl;
		switch (choice) 
		{
		case MAKE:
			MakeAccout();
			break;

		case DEPOSIT:
			DepositMoney();
			break;

		case WITHDRAW:
			WithdrawMoney();
			break;

		case DISPLAYINFO:
			ShowAllAccInfo();
			break;

		case EXIT:
			ExitTheProgram();
			return 0;
		}
	}
	return 0;
}

void ShowMenu() 
{
	std::cout << "--------Menu--------" << std::endl;
	std::cout << "1: Create Account" << std::endl;
	std::cout << "2: Deposit" << std::endl;
	std::cout << "3: Withdraw" << std::endl;
	std::cout << "4: Display Acc Info" << std::endl;
	std::cout << "5: Exit" << std::endl;
}

void MakeAccout() 
{
	int accNumber;
	std::string name;
	int balance;

	std::cout << "[Creating Account]" << std::endl;
	std::cout << "Account Number: "; std::cin >> accNumber; std::cout << std::endl;
	std::cout << "Initial Deposit: "; std::cin >> balance; std::cout << std::endl;
	std::cout << "Name: "; std::cin >> name; std::cout << std::endl;

	accArr[accNum++] = new Account(accNumber, balance, name);
}

void DepositMoney() 
{
	int money;
	int accNumber;
	std::cout << "[Deposit]" << std::endl;
	std::cout << "Account Number: "; std::cin >> accNumber; std::cout << std::endl;
	std::cout << "Amount of Money to Deposit: "; std::cin >> money; std::cout << std::endl;

	for (int i = 0; i < accNum; i++) 
	{
		if (accArr[i]->GetAccNumber() == accNumber) 
		{
			accArr[i]->Deposit(money);
			std::cout << "Successfully Deposited" << std::endl;
			return;
		}
		std::cout << "Not Correct Account Number" << std::endl;
	}
}

void WithdrawMoney() 
{
	int money;
	int accNum;
	std::cout << "[Withdraw]" << std::endl;
	std::cout << "Account Number: "; std::cin >> accNum; std::cout << std::endl;
	std::cout << "Amount of Money to Withdraw: "; std::cin >> money; std::cout << std::endl;

	for (int i = 0; i < accNum; i++) 
	{
		if (accArr[i]->GetAccNumber() == accNum) 
		{
			accArr[i]->Withdraw(money);
			std::cout << "Sucessfully Witdrawed" << std::endl;
			return;
		}
		std::cout << "Not Correct Account Number" << std::endl;
	}
}

void ShowAllAccInfo() 
{
	for (int i = 0; i < accNum; i++) 
	{
		accArr[i]->ShowAccInfo();
	}
}

void ExitTheProgram() 
{
	for (int i = 0; i < accNum; i++) 
	{
		delete accArr[i];
	}
	std::cout << "Program Exit" << std::endl;
	return;
}



