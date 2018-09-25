#pragma once
#ifndef HighCreditAccount_h
#define HighCreditAccount_h
#include "NormalAccount.h"
////int accNum, int balance, std::string name
class HighCreditAccount:public NormalAccount
{
private:
	int specialRate;
public:
	HighCreditAccount(int accNum, int balance, std::string name, int rate, int special);
	virtual void Deposit(int money);
};
#endif //HighCreditAccount_h

