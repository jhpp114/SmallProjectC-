#pragma once
#ifndef Account_h
#define Account_h
#include <iostream>
#include <string>

class Account
{
private:
	int accNumber;
	int balance;
	std::string accHolderName;
public:
	Account(int accNum, int balance, std::string name);
	Account(const Account &copy); //copy constructor
	int GetAccountNumber();
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccountInfo();
};
#endif //Account_h

