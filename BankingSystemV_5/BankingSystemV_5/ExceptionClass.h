#pragma once
#ifndef ExceptionClass_h
#define ExceptionClass_h
#include <iostream>
class NegativeMoneyException 
{
private:
	int moneyException;
public:
	NegativeMoneyException(int money) 
		:moneyException(money)
	{
		//empty
	}
	void ExceptionMessage() 
	{
		std::cout << moneyException << " is Not Right Amount" << std::endl;
	}
};

class WithdrawMoneyException 
{
private:
	int withdrawException;
	int currentBalance;
public:
	WithdrawMoneyException(int requestedMoney, int curBalance)
		:withdrawException(requestedMoney), currentBalance(curBalance)
	{
		//empty
	}
	void WithdrawExceptionMessage() 
	{
		std::cout << "You have Requested " << withdrawException << std::endl;
		std::cout << "Your Balance is " << currentBalance << std::endl;
		std::cout << "Not Enough Balance" << std::endl;
	}

};
#endif // ExceptionClass.h
