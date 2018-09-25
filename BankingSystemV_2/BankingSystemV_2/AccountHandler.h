#pragma once
#ifndef AccountHandler_h
#define AccountHandler_h
#include <iostream>
#include <string>
#include "Account.h"
class AccountHandler
{
private:
	Account *accArr[100]; //can contain 100 Accounts
	int numberOfAcc;
public:
	AccountHandler();
	void ShowMenu();
	void CreateAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAccInfo();
	~AccountHandler();
};
#endif AccountHandler_h

