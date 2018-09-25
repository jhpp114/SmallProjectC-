#include "pch.h"
#include "AccountHandler.h"

AccountHandler::AccountHandler() 
	:numberOfAcc(0)
{
	//empty
}

void AccountHandler::ShowMenu() 
{
	std::cout << "===========Menu==========" << std::endl;
	std::cout << "1: Create Account" << std::endl;
	std::cout << "2: Deposit" << std::endl;
	std::cout << "3: Withdraw" << std::endl;
	std::cout << "4: Display Account" << std::endl;
	std::cout << "5: Exit" << std::endl;
}

void AccountHandler::CreateAccount() 
{
	int choice;
	std::cout << "[Creating Account]" << std::endl;
	std::cout << "1:Normal Account" << std::endl;
	std::cout << "2:Credit Account" << std::endl;
	std::cout << "Select: "; std::cin >> choice; std::cout << std::endl;

	if (choice == NORMAL) 
	{
		MakeNormalAccount();
	}
	else
	{
		MakeCreditAccount();
	}
}

void AccountHandler::MakeNormalAccount() 
{
	int accNum;
	int initialBalance;
	std::string name;
	int interest;

	std::cout << "[Creating.. Normal Account]" << std::endl;
	std::cout << "Enter Account Number: "; std::cin >> accNum; std::cout << std::endl;
	std::cout << "Enter Name: "; std::cin >> name; std::cout << std::endl;
	std::cout << "Enter Initial Balance: "; std::cin >> initialBalance; std::cout << std::endl;
	std::cout << "Enter Interest Rate: "; std::cin >> interest; std::cout << std::endl;

	accArr[numberOfAcc++] = new NormalAccount(accNum, initialBalance, name, interest);
}
//int accNum, int balance, std::string name, int rate, int special
void AccountHandler::MakeCreditAccount() 
{
	int accNum;
	int balance;
	std::string name;
	int rate;
	int creditLevel;

	std::cout << "[Creating.. Credit Account]" << std::endl;
	std::cout << "Enter the Account Number: "; std::cin >> accNum; std::cout << std::endl;
	std::cout << "Enter Name: "; std::cin >> name; std::cout << std::endl;
	std::cout << "Enter Initial Balance: "; std::cin >> balance; std::cout << std::endl;
	std::cout << "Enter Interest Rate: "; std::cin >> rate; std::cout << std::endl;
	std::cout << "Enter Credit Level(1 TO A, 2 TO B, 3 TO C): "; std::cin >> creditLevel; std::cout << std::endl;

	switch (creditLevel) 
	{
	case 1:
		accArr[numberOfAcc++] = new HighCreditAccount(accNum, balance, name, rate, LEVEL_A);
		break;

	case 2:
		accArr[numberOfAcc++] = new HighCreditAccount(accNum, balance, name, rate, LEVEL_B);
		break;

	case 3:
		accArr[numberOfAcc++] = new HighCreditAccount(accNum, balance, name, rate, LEVEL_C);
		break;
	}
}

void AccountHandler::Deposit() 
{
	int accNumber;
	int money;
	std::cout << "[Deposit]" << std::endl;
	std::cout << "Enter Account Number: "; std::cin >> accNumber; std::cout << std::endl;
	std::cout << "Enter Money to Deposit: "; std::cin >> money; std::cout << std::endl;

	for (int i = 0; i < numberOfAcc; i++) 
	{
		if (accArr[i]->GetAccountNumber() == accNumber) 
		{
			std::cout << "Access" << accNumber << "Account" << std::endl;
			accArr[i]->Deposit(money);
			std::cout << "Successfully Deposited" << std::endl;
		}
		std::cout << "Invalid Account" << std::endl;
	}
}
void AccountHandler::Withdraw() 
{
	int accNumber;
	int money;
	std::cout << "[Withdraw]" << std::endl;
	std::cout << "Enter Account Number: "; std::cin >> accNumber; std::cout << std::endl;
	std::cout << "Enter Money to Withdraw: "; std::cin >> money; std::cout << std::endl;

	for (int i = 0; i < numberOfAcc; i++)
	{
		if (accArr[i]->GetAccountNumber() == accNumber)
		{
			if (accArr[i]->Withdraw(money) <= 0)
			{
				std::cout << "Not Enough Budget" << std::endl;
			}
			accArr[i]->Withdraw(money);
		}
		std::cout << "Invalid Account" << std::endl;
	}
}

void AccountHandler::ShowAccInfo()
{
	for (int i = 0; i < numberOfAcc; i++) 
	{
		accArr[i]->ShowAccountInfo();
	}
	std::cout << std::endl;
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < numberOfAcc; i++) 
	{
		delete accArr[i];
	}
}
