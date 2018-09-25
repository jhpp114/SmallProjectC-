#pragma once
#ifndef AccountHandler_h
#define AccountHandler_h
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonEnum.h"
#include <iostream>

class AccountHandler
{
private:
	Account *accArr[100];
	int numberOfAcc;
public:
	AccountHandler();
	void ShowMenu();
	void CreateAccount();
	void Deposit();
	void Withdraw();
	void ShowAccInfo();
	~AccountHandler();
protected:
	void MakeNormalAccount();
	void MakeCreditAccount();
};
#endif AccountHandler_h

