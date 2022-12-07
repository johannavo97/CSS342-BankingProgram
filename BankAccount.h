#pragma once
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const string FUND_TYPES[10] = {"Money Market","Prime Money Market","Long-Term Bond",
				"Short-Term Bond","500 Index Fund","Capital Value Fund",
				"Growth Equity Fund","Growth Index Fund",
				"Value Fund","Value Stock Index"};

class BankAccount
{
	public:

		// ============== Constructor/Destructors =============

		BankAccount();
		BankAccount(string last, string first, int id);
		~BankAccount();

		// ============ Accessor Functions =================

		string getLastName() const;
		string getFirstName() const;
		int getID() const;
		int getAccountBalance() const;
		Fund getFund(int fundID) const;

		void setFirstName(string first);
		void setLastName(string last);
		void setID(int newID);

		void printAccountHistory();
		void printSingleFundHistory();

		bool addToFundHistory(int fundID, string txn);

		// =============== Operation Overloading ===================

	private:
		Fund funds[10];
		string lastname;
		string firstname;
		int id;
};
