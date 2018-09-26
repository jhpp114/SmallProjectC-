#include "pch.h"
#include "HighCreditAccount.h"


HighCreditAccount::HighCreditAccount(int accNum, std::string name, int balance, int interest, int special)
	:NormalAccount(accNum, name, balance, interest), specialInterest(special)
{
	//empty	
}
void HighCreditAccount::Deposit(int money) 
{
	if (money < 0) 
	{
		throw NegativeMoneyException(money);
	}
	NormalAccount::Deposit(money);
	HighCreditAccount::Deposit(money *(specialInterest*100.0));
}