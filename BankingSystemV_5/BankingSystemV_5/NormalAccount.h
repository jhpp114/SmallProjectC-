#pragma once
#ifndef NormalAccount_h
#define NormalAccount_h
#include <iostream>
#include "Account.h"
#include "ExceptionClass.h"
class NormalAccount:public Account
{
private:
	int normalInterest;
public:
	NormalAccount(int accNum, std::string name, int balance, int interest);
	virtual void Deposit(int money);
};
#endif // NormalAccount_h

