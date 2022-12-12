// William Bach
// CSS342 Fall22
// Program 5 - Jolly Banker
#include "BankAccount.h"
#include "Funds.h"
#include "Funds.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

BankAccount::BankAccount() : lastname(""), firstname(""), id(0) {}

BankAccount::BankAccount(string last, string first, int id)
{
	this->lastname = last;
	this->firstname = first;
	this->id = id;
	for (int i = 0; i < 10; i++)
	{
		funds[i].setFundName(FUND_TYPES[i]);
		funds[i].setBalance(0);
	}
}

BankAccount::~BankAccount(){}


string BankAccount::getLastName() const
{
	return lastname;
}

string BankAccount::getFirstName() const
{
	return firstname;
}

int BankAccount::getID() const
{
	return this->id;
}

void BankAccount::setLastName(string lname)
{
	this->lastname = lname;
}

void BankAccount::setFirstName(string fname)
{
	this->firstname = fname;
}

void BankAccount::setID(int newID)
{
	this->id = newID;
}

int BankAccount::getAccountBalance() const // Returns the total balance in the account
{
	int temp;
	for(int i = 0; i < 10; i++)
	{
		temp+=funds[i].getBalance();
	}
	return temp;
}

string BankAccount::getSubAccName(int fundID) const  // returns the name of the fund account
{
	return this->funds[fundID].getFundName();
}

int BankAccount::getSubAccBalance(int fundID) const // returns the balance in the fund account
{
	return this->funds[fundID].getBalance();
}

// =============== Print Histories ==============

// Prints out the total history for all funds in the account
void BankAccount::printAccountHistory() 
{
	ofstream outfile;
	outfile.open("BankTransOut.txt", std::ios_base::app);
	outfile << "Transaction History for " << this->firstname << " " << this->lastname << " by fund.\n";
	outfile.close();
	for(int i = 0; i < 10; i++)
	{
		funds[i].printFundHistory();
	}
}

// Prints out the history of a specified fund
void BankAccount::printSingleFundHistory(int fundID)
{	
	ofstream outfile;
	outfile.open("BankTransOut.txt", std::ios_base::app);
	outfile << "Transaction History for " << this->firstname << " " << this->lastname << " " << this->funds[fundID].getFundName() << ": $" << this->funds[fundID].getBalance() << endl;
	outfile.close();
	funds[fundID].printFundHistory(); 
}
