#include "pch.h"
#include "Account.h"

Account::Account(int accNum, int balance, std::string name) 
	:accNumber(accNum), balance(balance)
{
	accHolderName = name;
}

Account::Account(const Account& copy) 
	:accNumber(copy.accNumber), balance(copy.balance)
{
	accHolderName = copy.accHolderName;
}

int Account::GetAccountNumber() 
{
	return accNumber;
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
	std::cout << "Account Number: " << accNumber << std::endl;
	std::cout << "Account Holder Name: " << accHolderName << std::endl;
	std::cout << "Balance: " << balance << std::endl;
}