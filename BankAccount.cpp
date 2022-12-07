#include "BankAccount.h"
#include "Fund.h"
#include <iostream>

// const string FUND_TYPES[10] = {"Money Market","Prime Money Market","Long-Term Bond","Short-Term Bond",
// 				"500 Index Fund","Capital Value Fund","Growth Equity Fund","Growth Index Fund",
// 				"Value Fund","Value Stock Index"};

// ============== Constructor/Destructors =============

BankAccount::BankAccount() : last(""), first(""), id(0) {}

BankAccount::BankAccount(string last, string first, int id)
{
	this->lastname = last;
	this->firstname = first;
	this->accountID = id;
	for (int i = 0; i < 10; i < i++)
	{
		funds[i].setFundType(FUND_TYPES[i]);
		funds[i].setFundBalance(0);
	}
}

BankAccount::~BankAccount(){}

// ============ Accessor Functions =================
// ============ Getter/Setters =====================

int BankAccount::getLastName() const
{
	return lastname;
}

int BankAccount::getFirstName() const
{
	return firstname;
}

int BankAccount::getLastName() const
{
	return accountID;
}

void BankAccount::setLastName(string lname)
{
	this->lastname = lname;
}

void BankAccount::setFirstName(string fname)
{
	this->firstname = lname;
}

void BankAccount::setID(string id)
{
	this->accountID = id;
}

int BankAccount::getAccountBalance() const
{
	int temp;
	for(int i = 0; i < 10; i++)
	{
		temp+=funds[i].getBalance();
	}
	return temp;
}

Fund BankAccount::getFund(int fundID) const
{
	return this->funds[fundID];
}

// =============== Print Histories ==============

void BankAccount::printAccountHistory()
{

	cout << "Transaction History for " << this->firstname << this->lastname << " by fund.\n"
	for(int i = 0; i < 10; i++)
	{
		funds[i].printFundHistory();
	}
}

void BankAccount::printSingleFundHistory(int fundID)
{	
	cout << "Transaction History for " << this->firstname << this->lastname << " " << funds[fundID] << ": $" << funds[fundID].getBalance() << "\n";
	funds[fundID].printFundHistory(); 
}

// =============== Add to history ==========================

bool BankAccount::addToFundHistory(int fundID, string txn)
{
	funds[fundID].addToHistory(string txn);
	return true;
}

// =============== Operation Overloading ===================
