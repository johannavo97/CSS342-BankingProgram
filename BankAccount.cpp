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
	for (int i = 0; i < 10; i < i++)
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

int BankAccount::getAccountBalance() const
{
	int temp;
	for(int i = 0; i < 10; i++)
	{
		temp+=funds[i].getBalance();
	}
	return temp;
}

// Fund BankAccount::getFund(int fundID) const
// {
// 	return this->funds[fundID];
// }

string BankAccount::getSubAccName(int fundID) const
{
	return this->funds[fundID].getFundName();
}

int BankAccount::getSubAccBalance(int fundID) const
{
	return this->funds[fundID].getBalance();
}

// ****** Depositing money into fund *******

// bool BankAccount::deposit(int amount, int fundID, string txn)
// {
// 	this->funds[fundID].depositMoney(amount);
// 	this->funds[fundID].addToHistory(txn);
// 	return true;
// }

// ****** Withdrawing money from fund *******

// bool BankAccount::withdraw(int amount, int fundID, string txn)
// {
// 	if(!this->funds[fundID].withdrawPossible()) // If not enough money in fund
// 	{
// 		if(fundID==0) // If withdrawing from money market account
// 		{
// 			return coveringFunds(fundID, amount, 1, txn);
// 		}
// 		else if(fundID==1) //If withdrawing from Prime Money Market
// 		{
// 			return coveringFunds(fundID, amount, 0, txn);
// 		}
// 		else if(fund1==2) // // If withdrawing from long term bond
// 		{
// 			return coveringFunds(fundID, amount, 3, txn);
// 		}
// 		else if(fund1==3) // If withdrawing from short term bond
// 		{
// 			return coveringFunds(fundID, amount, 2, txn);
// 		}
// 		else
// 		{
// 			this->funds[fundID].addToHistoryWithError(txn);
// 			return false;
// 		}
// 	}
// 	else
// 	{
// 		this->funds[fundID].withdrawMoney(amount);
// 		this->funds[fundID].addToHistory(txn);
// 		return true;
// 	}
// }
// ****** In-account transfer *******

// bool BankAccount::transferFunds(int fund1, int amount, int fund2, string txn)
// {
// 	if(!this->funds[fundID].withdrawPossible()) // If not enough money in fund
// 	{
// 		if(fund1==0 && fund2 != 1) // If withdrawing from money market account
// 		{
// 			coveringFundsInSameAccount(fund1, 1, amount, fund2, txn);
// 		}
// 		else if(fund1==1 && fund2 != 0) //If withdrawing from Prime Money Market
// 		{
// 			coveringFundsInSameAccount(fund1, 0, amount, fund2, txn);
// 		}
// 		else if(fund1==2 && fund2 != 3) // If withdrawing from long term bond
// 		{
// 			coveringFundsInSameAccount(fund1, 3, amount, fund2, txn);
// 		}
// 		else if(fund1==3 && fund2 != 2) // If withdrawing from short term bond
// 		{
// 			coveringFundsInSameAccount(fund1, 2, amount, fund2, txn);
// 		}
// 		else
// 		{
// 			this->funds[fund1].addToHistoryWithError(txn);
// 			return false;
// 		}
// 	}
// 	else
// 	{
// 		this->funds[fund1].withdrawMoney(amount);
// 		this->funds[fund1].addToHistory(txn);
// 		this->funds[fund2].depositMoney(amount);
// 		this->funds[fund2].addToHistory(txn);
// 		return true;
// 	}
// }

// =============== Print Histories ==============

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

void BankAccount::printSingleFundHistory(int fundID)
{	
	ofstream outfile;
	outfile.open("BankTransOut.txt", std::ios_base::app);
	outfile << "Transaction History for " << this->firstname << " " << this->lastname << " " << this->funds[fundID].getFundName() << ": $" << this->funds[fundID].getBalance() << endl;
	outfile.close();
	funds[fundID].printFundHistory(); 
}

// =============== Add to history ==========================

// bool BankAccount::addToFundHistory(int fundID, string txn)
// {
// 	funds[fundID].addToHistory(string txn);
// 	return true;
// }

// =============== Operation Overloading ===================

// ================ Helper Functions =======================

// bool BankAccount::coveringFunds(int fund1, int amount, int fund2, string txn)
// {
// 	if(this->funds[fund1].getBalance()+this->funds[fund2].getBalance()>=amount) // If secondary fund can cover
// 	{
// 		int temp = this->funds[fund1].withdrawAllMoney();
// 		this->funds[fund1].addToHistory(txn);
// 		this->funds[fund2].withdrawMoney(temp);
// 		this->funds[fund2].addToHistory(txn);
// 		return true;
// 	}
// 	else
// 	{
// 		this->funds[fundID].addToHistoryWithError(txn);
// 		return false;
// 	}
// }

// bool BankAccount::coveringFundsInSameAccount(int fund1, int secondaryFund, int amount, int fund2, string txn)
// {
// 	if(this->funds[fund1].getBalance()+this->funds[fund2].getBalance()>=amount) // If secondary fund can cover
// 	{
// 		int temp = this->funds[fund1].withdrawAllMoney();
// 		this->funds[fund1].addToHistory(txn);
// 		this->funds[secondaryFund].withdrawMoney(temp);
// 		this->funds[secondaryFund].addToHistory(txn);
// 		this->funds[fund2].depositMoney(amount);
// 		this->funds[fund2].addToHistory(txn);
// 		return true;
// 	}
// 	else
// 	{
// 		this->funds[fund1].addToHistoryWithError(txn);
// 		return false;
// 	}
// }
