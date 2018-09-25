#pragma once
#ifndef NormalAccount_h
#define NormalAccount_h
#include <iostream>
#include <string>
#include "Account.h"
class NormalAccount:public Account
{
private:
	int interestRate;
public:
	NormalAccount(int accNum, int balance, std::string name, int interest);
	virtual void Deposit(int money);
};
#endif //NormalAccount_h
