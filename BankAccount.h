#pragma once
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

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

		void setFirstName(string first);
		void setLastName(string last);
		void setID(int newID);

		// =============== Operation Overloading ===================

	private:
		string lastname;
		string firstname;
		int id;
};