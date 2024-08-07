// Name: Eduardo Salazar
// NSHE: 5005695833
// Assignment: 6
// Description: use a hashmap to store and simulate bank information and transactions
#include "hashMap.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

struct bankType
{
	struct transactionType
	{
		transactionType(bool t, double a)
		{
			type = t;
			amount = a;
		}

		bool type;
		double amount;
	};

	bankType(std::string first, std::string last, std::string acctNo,
		double balance,unsigned int pin)
	{
		name = last + ", " + first;
		this->balance = balance;
		this->pin = pin;
		this->acctNo = acctNo;
		locked = false;
	}

	bankType()
	{
		name = "";
		balance = 0;
		pin = 0;
		locked = false;
	}

	std::string name;
	std::string acctNo;
	double balance;
	unsigned int pin;
	bool locked;

	std::vector<transactionType> transactions;
};

bool cont();																				// asks the user if they wish to continue
std::string lowerCase(std::string);															// converts string to all lowercase chars

int main()
{
	std::cout << std::fixed << std::setprecision(2);
	hashMap< std::string, hashMap< std::string, bankType >> bank;

	hashMap< std::string, bool> locations;													// used to store locations
	std::string header, line, first, last, location, acc_num;								// store bankType information
	std::string balance_string, four_Digits;
	double balance;
	unsigned int pin;
	std::ifstream iFile("data.csv");
	
	std::getline(iFile,header);																	// read in first line of file
	while(!iFile.eof())																		// read in the file
	{
		std::getline(iFile,line);
		if(line.length() == 0)
			break;
		first = line.substr(0,line.find(","));
		line.erase(0,line.find(",") + 1);
		last = line.substr(0,line.find(","));
		line.erase(0,line.find(",") + 1);
		location = line.substr(0,line.find(","));
		line.erase(0,line.find(",") + 1);
		acc_num = line.substr(0,line.find(","));
		four_Digits = acc_num.substr(acc_num.length()-4,acc_num.length());					// get last 4 digits
		line.erase(0,line.find(",") + 1);
		balance_string = line.substr(0,line.find(","));
		balance = std::stod(balance_string);												// convert to double
		line.erase(0,line.find(",") + 1);
		pin = std::stoi(line);																// convert to int

		bank[lowerCase(location)][four_Digits] = bankType(first,last,acc_num,balance,pin);
		locations[lowerCase(location)] = true;
	}
	iFile.close();																			// close file

	std::string bank_location;
	bool exit;																				// used to exit second while loop

	while(1)
	{
		exit = false;																		// sets/resets bool to false

		std::cout << "Please enter bank branch location: ";
		getline(std::cin,bank_location);
		std::cout << std::endl;
		bank_location = lowerCase(bank_location);

		if(locations[bank_location] != true)												// if bank location is not valid
		{
			std::cout << "Bank branch not found" << std::endl << std::endl;
			if(cont() == false)
				return 0;
			else
			{
				std::cin.clear();																						// clear and reset stanard input
				std::cin.ignore(100,'\n');
				continue;
			}
		}

		std::cout << "Enter last 4 digits of account: ";
		std::cin >> four_Digits;
		std::cout << std::endl;

		if(bank[bank_location][four_Digits].name == "")										// if the account number is not found
		{
			std::cout << "Account not found" << std::endl << std::endl;
			std::cin.clear();
			std::cin.ignore(100,'\n');
			if(cont() == false)
				return 0;
			else
			{
				std::cin.clear();																						// clear and reset stanard input
				std::cin.ignore(100,'\n');
				continue;
			}
		}

		if(bank[bank_location][four_Digits].locked == true)									// if the account is locked
		{
			std::cout << "Account has a lock" << std::endl << std::endl;
			std::cin.clear();
			std::cin.ignore(100,'\n');
			if(cont() == false)
				return 0;
			else
			{
				std::cin.clear();																						// clear and reset stanard input
				std::cin.ignore(100,'\n');
				continue;
			}
		}

		int pin_counter = 0;
		do{
			std::cout << "Enter a pin: ";
			std::cin >> pin;
			std::cout << std::endl;

			if(bank[bank_location][four_Digits].pin != pin)									// if the pin entered is incorrect
			{
				std::cin.clear();
				std::cin.ignore(100,'\n');
				std::cout << "Invalid pin" << std::endl << std::endl;
				pin_counter++;
			}
			else
				break;
		}while(pin_counter < 3);

		if(pin_counter == 3)																								// if pin is enetered incorrectly 3 times
		{
			bank[bank_location][four_Digits].locked = true;																	// lock the account
			std::cout << "3 failed login attempts, account is now locked" << std::endl << std::endl;
			if(cont() == false)
				return 0;
			else
			{
				std::cin.clear();																						// clear and reset stanard input
				std::cin.ignore(100,'\n');
				continue;
			}
		}

		char choice;
		double deposit,withdrawal;

		while(exit == false)																								// loop until user chooses to quit
		{
			std::cout << "(D)eposit" << std::endl;
			std::cout << "(W)ithdrawal" << std::endl;
			std::cout << "(V)iew account" << std::endl;
			std::cout << "(E)xit account" << std::endl;
			std::cout << "Enter choice: ";
			std::cin >> choice;
			std::cout << std::endl;

			switch (choice)																									// switch to perform choice selected
			{
			case 'D': case 'd':																								// DEPOSIT
				std::cout << "Enter deposit amount: ";
				std::cin >> deposit;
				std::cout << std::endl;
				bank[bank_location][four_Digits].balance += deposit;
				bank[bank_location][four_Digits].transactions.push_back(bankType::transactionType(true,deposit));			// store transaction
				break;
			case 'W': case 'w':																								// WITHDRAWAL
				std::cout << "Enter withdrawal amount: ";
				std::cin >> withdrawal;
				std::cout << std::endl;
				if(bank[bank_location][four_Digits].balance >= withdrawal)
				{
					bank[bank_location][four_Digits].balance -= withdrawal;
					bank[bank_location][four_Digits].transactions.push_back(bankType::transactionType(false,withdrawal));	//store transaction
				}
				else
					std::cout << "Not enough funds to make transaction" << std::endl << std::endl;
				break;
			case 'V': case 'v':																								// VIEW ACCOUNT
				std::cout << "Name: " << bank[bank_location][four_Digits].name << std::endl;
				std::cout << "Balance: $" << bank[bank_location][four_Digits].balance << std::endl << std::endl;

				if(bank[bank_location][four_Digits].transactions.size() == 0)
					std::cout << "No transactions" << std::endl << std::endl;
				else
				{
					std::cout << "List of transactions" << std::endl;
					for(int i = 0; i < bank[bank_location][four_Digits].transactions.size(); i++)
					{
						if(bank[bank_location][four_Digits].transactions[i].type == true)
							std::cout << "Deposit amount $" << bank[bank_location][four_Digits].transactions[i].amount << std::endl;
						else
							std::cout << "Withdrawal amount $" << bank[bank_location][four_Digits].transactions[i].amount << std::endl;
					}
					std::cout << std::endl;
				}
				break;
			case 'E': case 'e':																								// EXIT
				if(cont() == false)
					return 0;
				exit = true;
				break;
			default:																										// ERROR
				std::cout << "Invalid choice" << std::endl;
				break;
			}
			std::cin.clear();																								// clear input
			std::cin.ignore(100,'\n');
		}
	}

	return 0;
}
// prompts the user to continue
bool cont()
{
	char a;
	std::cout << "Continue? (Y/N): ";
	std::cin >> a;
	std::cout << std::endl;
	if(a == 'Y' || a == 'y')
		return true;

	return false;
}
// convert string to lowercase chars
std::string lowerCase(std::string name)
{
	for(int i = 0; i < name.length(); i++)
		name[i] = tolower(name[i]);

	return name;
}