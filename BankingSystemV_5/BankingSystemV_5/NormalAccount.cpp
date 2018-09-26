#include "pch.h"
#include "NormalAccount.h"

NormalAccount::NormalAccount(int accNum, std::string name, int balance, int interest) 
	:Account(accNum, name, balance), normalInterest(interest)
{
	//empty
}
void NormalAccount::Deposit(int money) 
{
	if (money < 0) 
	{
		throw NegativeMoneyException(money);
	}
	Account::Deposit(money);
	Account::Deposit(money *(normalInterest*100.0));
}
