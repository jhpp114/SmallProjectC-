#include "pch.h"
#include "NormalAccount.h"
//(int accNum, int balance, std::string name)
NormalAccount::NormalAccount(int accNum, int balance, std::string name, int interest) 
	:Account(accNum, balance, name), interestRate(interest)
{
	//empty
}

void NormalAccount::Deposit(int money) 
{
	Account::Deposit(money);
	Account::Deposit(money *(interestRate / 100.0));
}
