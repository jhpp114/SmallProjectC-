#pragma once
#ifndef Account_h
#define Account_h
#include <iostream>
#include <string>
#include "ExceptionClass.h"

class Account
{
private:
	int accNumber;
	std::string accHolder;
	int balance;
public:
	Account(int accNum, std::string name, int balance);
	virtual void Deposit(int money);
	int GetAccountNumber();
	int Withdraw(int money);
	void ShowAccountInfo();
};
#endif //Account_h

