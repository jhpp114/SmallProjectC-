#include "pch.h"
#include "AccountHandler.h"
#include <iostream>
#include <string>

AccountHandler::AccountHandler()
	:numberOfAcc(0)
{
	//empty;
}

void AccountHandler::ShowMenu() 
{
	std::cout << "----------Menu-----------" << std::endl;
	std::cout << "1:Create Account" << std::endl;
	std::cout << "2:Deposit" << std::endl;
	std::cout << "3:Withdraw" << std::endl;
	std::cout << "4:Show Account Infomation" << std::endl;
	std::cout << "5:Exit" << std::endl;
}
void AccountHandler::CreateAccount() 
{
	int accNumber;
	int balance;
	std::string holderName;

	std::cout << "[Creating Account]" << std::endl;
	std::cout << "Account Number: "; std::cin >> accNumber; std::cout << std::endl;
	std::cout << "Initial Balance: "; std::cin >> balance; std::cout << std::endl;
	std::cout << "Account Holder Name: "; std::cin >> holderName; std::cout << std::endl;

	accArr[numberOfAcc++] = new Account(accNumber, holderName, balance);
}
void AccountHandler::DepositMoney() 
{
	int money;
	int accNumber;
	std::cout << "Enter Account Number: "; std::cin >> accNumber; std::cout << std::endl;
	std::cout << "Enter Money to Deposit: "; std::cin >> money; std::cout << std::endl;

	for (int i = 0; i < numberOfAcc; i++) 
	{
		if (accArr[i]->GetAccountNumber() == accNumber) 
		{
			std::cout << "Accessing the Bank Account: " << accNumber << std::endl;
			accArr[i]->Deposit(money);
			std::cout << "Successfully Deposited" << std::endl;
		}
		std::cout << "Invalid Account Number" << std::endl;
	}
}
void AccountHandler::WithdrawMoney() 
{
	int money;
	int accNumber;
	std::cout << "Enter Account Number: "; std::cin >> accNumber; std::cout << std::endl;
	std::cout << "Enter Money to Withdraw: "; std::cin >> money; std::cout << std::endl;

	for (int i = 0; i < numberOfAcc; i++) 
	{
		if (accArr[i]->GetAccountNumber() == accNumber) 
		{
			std::cout << "Accessing the Bank Account: " << std::endl;
			accArr[i]->Withdraw(money);
			std::cout << "Successfully Withdrawed" << std::endl;
		}
		std::cout << "Invalid Account Number" << std::endl;
	}
}
void AccountHandler::ShowAccInfo() 
{
	for (int i = 0; i < numberOfAcc; i++) 
	{
		accArr[i]->ShowAccountInfo();
	}
	std::cout << std::endl;
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < numberOfAcc; i++) 
	{
		delete accArr[i];
	}
}
