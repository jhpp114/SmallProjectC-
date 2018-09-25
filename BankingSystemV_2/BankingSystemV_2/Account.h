#pragma once
#ifndef Account_h
#define Account_h
#include <iostream>
#include <string>

class Account
{
private:
	int accNum;
	int balance;
	std::string name;
public:
	Account(int accNumber, std::string holderName, int initBalance);
	int GetAccountNumber();
	void Deposit(int money);
	int Withdraw(int money);
	void ShowAccountInfo();
};
#endif //Account_h

