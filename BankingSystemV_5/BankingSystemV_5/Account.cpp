#include "pch.h"
#include "Account.h"

Account::Account(int accNum, std::string name, int money) 
	:accNumber(accNum), balance(money)
{
	accHolder = name;
}

void Account::Deposit(int money) 
{
	if (money <= 0) 
	{
		throw NegativeMoneyException(money);
	}
	balance += money;
}

int Account::GetAccountNumber() 
{
	return accNumber;
}

int Account::Withdraw(int money) 
{
	if (money < 0) 
	{
		throw NegativeMoneyException(money);
	}
	if (balance < money) 
	{
		throw WithdrawMoneyException(money, balance);
	}
	balance -= money;
	return balance;
}

void Account::ShowAccountInfo() 
{
	std::cout << std::endl;
	std::cout << "[Display Account Information]" << std::endl;
	std::cout << "Accout Number: " << accNumber << std::endl;
	std::cout << "Account Holder Name: " << accHolder << std::endl;
	std::cout << "Account Balance: " << balance << std::endl;
}