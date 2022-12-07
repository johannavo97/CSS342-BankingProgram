#include "BankAccount.h"
#include "Fund.h"
#include <iostream>

// const string FUND_TYPES[10] = {"Money Market","Prime Money Market","Long-Term Bond","Short-Term Bond",
// 								"500 Index Fund","Capital Value Fund","Growth Equity Fund","Growth Index Fund",
// 								"Value Fund","Value Stock Index"};

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

// Fund BankAccount::getFund(int fundID) const
// {
// 	return this->funds[fundID];
// }

string BankAccount::getSubAccName(int fundID) const
{
	return this->funds[fundID].getType();
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

	cout << "Transaction History for " << this->firstname << this->lastname << " by fund.\n"
	for(int i = 0; i < 10; i++)
	{
		funds[i].printFundHistory();
	}
}

// void BankAccount::printSingleFundHistory(int fundID)
// {	
// 	cout << "Transaction History for " << this->firstname << this->lastname << " " << funds[fundID] << ": $" << funds[fundID].getBalance() << "\n";
// 	funds[fundID].printFundHistory(); 
// }

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
