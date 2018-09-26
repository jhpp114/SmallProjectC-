#include "pch.h"
#include "AccountHandler.h"


AccountHandler::AccountHandler()
	:numberOfAccount(0)
{
	//empty
}

void AccountHandler::ShowMenu() 
{
	std::cout << "===========Menu============" << std::endl;
	std::cout << "1:Create Account" << std::endl;
	std::cout << "2:Deposit" << std::endl;
	std::cout << "3:Withdraw" << std::endl;
	std::cout << "4:Show Account Information" << std::endl;
	std::cout << "5:Exit" << std::endl;
}

void AccountHandler::CreateAccount()
{
	int choice;
	std::cout << "[Creating Account Selection]" << std::endl;
	std::cout << "1:Normal Account  2:HighCredit Account" << std::endl;
	std::cout << "Enter Your Choice "; std::cin >> choice; std::cout << std::endl;
	if (choice == NORMAL)
	{
		MakeNormalAccount();
	}
	else 
	{
		MakeHighCreditAccount();
	}
}

void AccountHandler::MakeNormalAccount() 
{
	int accNum;
	std::string accHolder;
	int initBalance;
	int interest;

	std::cout << "[Creating Normal Account]" << std::endl;
	std::cout << "Account Number: "; std::cin >> accNum; std::cout << std::endl;
	std::cout << "Account Holder Name: "; std::cin >> accHolder; std::cout << std::endl;
	std::cout << "Initial Deposit: "; std::cin >> initBalance; std::cout << std::endl;
	std::cout << "Interest Rate: "; std::cin >> interest; std::cout << std::endl;

	accArr[numberOfAccount++] = new NormalAccount(accNum, accHolder, initBalance, interest);
}

void AccountHandler::MakeHighCreditAccount() 
{
	int accNum;
	std::string accHolder;
	int initBalance;
	int interest;
	int creditLevel;

	std::cout << "[Creating HighCredit Account]" << std::endl;
	std::cout << "Account Number: "; std::cin >> accNum; std::cout << std::endl;
	std::cout << "Account Holder Name: "; std::cin >> accHolder; std::cout << std::endl;
	std::cout << "Initial Balance: "; std::cin >> initBalance; std::cout << std::endl;
	std::cout << "Interest Rate: "; std::cin >> interest; std::cout << std::endl;
	std::cout << "Credit_Level (1 To A), (2 To B), (3 To C): "; std::cin >> creditLevel; std::cout << std::endl;
	//int accNum, std::string name, int balance, int interest, int special
	switch (creditLevel) 
	{
	case 1:
		accArr[numberOfAccount++] = new HighCreditAccount(accNum, accHolder, initBalance, interest, LEVEL_A);
		break;

	case 2:
		accArr[numberOfAccount++] = new HighCreditAccount(accNum, accHolder, initBalance, interest, LEVEL_B);
		break;

	case 3:
		accArr[numberOfAccount++] = new HighCreditAccount(accNum, accHolder, initBalance, interest, LEVEL_C);
		break;
	}
}

void AccountHandler::Deposit() 
{
	std::cout << "[Deposit]" << std::endl;
	int accNum;
	int depositMoney;

	std::cout << "Enter Account Number: "; std::cin >> accNum; std::cout << std::endl;

	while (true) 
	{
		std::cout << "Enter Deposit Money: "; std::cin >> depositMoney; std::cout << std::endl;
		try 
		{
			for (int i = 0; i < numberOfAccount; i++) 
			{
				if (accArr[i]->GetAccountNumber() == accNum) 
				{
					std::cout << "Accessed to Account" << std::endl;
					accArr[i]->Deposit(depositMoney);
					std::cout << "Deposited" << std::endl;
					return;
				}
			}
			std::cout << "Not Valid Account Number" << std::endl;
			return;
		}
		catch (NegativeMoneyException &expn) 
		{
			expn.ExceptionMessage();
			std::cout << "Re-Enter Deposit Money" << std::endl;
		}
	}
}

void AccountHandler::Withdraw() 
{
	int accNum;
	int withdrawMoney;
	std::cout << "Enter Account Number: "; std::cin >> accNum; std::cout << std::endl;
	while (true)
	{
		std::cout << "Enter Money to Withdraw: "; std::cin >> withdrawMoney; std::cout << std::endl;
		try
		{
			for (int i = 0; i < numberOfAccount; i++)
			{
				if (accArr[i]->GetAccountNumber() == accNum)
				{
					std::cout << "Accessed Account" << std::endl;
					accArr[i]->Withdraw(withdrawMoney);
					std::cout << "Withdrawed!" << std::endl;
					return;
				}
			}
			std::cout << "Not Valid Account Number" << std::endl;
			return;
		}
		catch (NegativeMoneyException &expn)
		{
			expn.ExceptionMessage();
			std::cout << "Enter the Money More than Zero" << std::endl;
		}
		catch (WithdrawMoneyException &expn) 
		{
			expn.WithdrawExceptionMessage();
			std::cout << "Re-Enter the Amount" << std::endl;
		}
	}
}

void AccountHandler::ShowAccountInfo() 
{
	for (int i = 0; i < numberOfAccount; i++) 
	{
		accArr[i]->ShowAccountInfo();
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < numberOfAccount; i++) 
	{
		delete accArr[i];
	}
}
