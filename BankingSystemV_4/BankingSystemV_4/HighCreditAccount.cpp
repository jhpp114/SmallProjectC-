#include "pch.h"
#include "HighCreditAccount.h"

//
HighCreditAccount::HighCreditAccount(int accNum, int balance, std::string name, int rate, int special) 
	:NormalAccount(accNum, balance, name, rate), specialRate(special)
{
	//empty
}
void HighCreditAccount::Deposit(int money)
{
	NormalAccount::Deposit(money);
	Account::Deposit(money * (specialRate / 100.0));
}