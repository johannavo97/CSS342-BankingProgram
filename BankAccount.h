// William Bach
// CSS342 Fall22
// Program 5 - Jolly Banker
#pragma once
#include "Funds.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const string FUND_TYPES[10] = {"Money Market","Prime Money Market","Long-Term Bond",
				"Short-Term Bond","500 Index Fund","Capital Value Fund",
				"Growth Equity Fund","Growth Index Fund",
				"Value Fund","Value Stock Index"};

class BankAccount
{
	public:
		Funds funds[10];
		BankAccount();
		BankAccount(string last, string first, int id);
		~BankAccount();

		string getLastName() const;
		string getFirstName() const;
		int getID() const;
		int getAccountBalance() const;
	
		string getSubAccName(int fundID) const;
		int getSubAccBalance(int fundID) const;

		void setFirstName(string first);
		void setLastName(string last);
		void setID(int newID);

		void printAccountHistory();
		void printSingleFundHistory(int fundID);


	private:
		string lastname;
		string firstname;
		int id;
};
