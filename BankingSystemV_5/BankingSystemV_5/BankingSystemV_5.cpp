// BankingSystemV_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include "AccountHandler.h"
#include "BankingCommonEnum.h"
int main()
{
	AccountHandler manager;
	int selection;
	while (true) 
	{
		manager.ShowMenu();
		std::cout << "Make Your Selection: "; std::cin >> selection; std::cout << std::endl;
		switch (selection) 
		{
		case MAKE:
			manager.CreateAccount();
			break;

		case DEPOSIT:
			manager.Deposit();
			break;

		case WITHDRAW:
			manager.Withdraw();
			break;

		case DISPLAY:
			manager.ShowAccountInfo();
			break;

		case EXIT:
			return 0;

		default:
			std::cout << "Illegal Selection" << std::endl;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
