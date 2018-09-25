#include "pch.h"
#include "Account.h"
#include <iostream>
#include <string>

Account::Account(int accNumber, std::string holderName, int initBalance) 
	:accNum(accNumber), balance(initBalance)
{
	name = holderName;
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
}
int Account::GetAccountNumber() 
{
	return accNum;
}
void Account::ShowAccountInfo() 
{
	std::cout << "Account Holder Name: " << name << std::endl;
	std::cout << "Acc Number: " << accNum << std::endl;
	std::cout << "Balance: " << balance << std::endl;
}


