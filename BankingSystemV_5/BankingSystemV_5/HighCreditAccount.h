#pragma once
#ifndef HighCreditAccont_h
#define HighCreditAccount_h
#include "NormalAccount.h"
//#include "ExceptionClass.h"
class HighCreditAccount:public NormalAccount
{
private:
	int specialInterest;
public:
	HighCreditAccount(int accNum, std::string name, int balance, int interest, int special);
	virtual void Deposit(int money);
};
#endif //HighCreditAccount_h

