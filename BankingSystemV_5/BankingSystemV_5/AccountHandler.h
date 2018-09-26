#pragma once
#ifndef AccountHandler_h
#define AccountHandler_h
#include "BoundCheckArray.h"
#include "Account.h"
#include "BankingCommonEnum.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include <iostream>
class AccountHandler
{
private:
	BoundCheckArray<Account*> accArr;
	int numberOfAccount;
public:
	AccountHandler();
	void ShowMenu();
	void CreateAccount();
	void Deposit();
	void Withdraw();
	void ShowAccountInfo();
	~AccountHandler();

protected:
	void MakeNormalAccount();
	void MakeHighCreditAccount();
};
#endif //AccountHandler_h

