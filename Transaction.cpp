// Transactions.cpp
// Created by Chris Jensen
// Created on December 9, 2022
// Last Edited December 11, 2022
// A part of Program5 JollyBanker

#include "Transactions.h"
#include "BSTree.h"
using namespace std;
	//Gathers account information from banker and creates account instance which is inserted into BSTree

Transactions::Transactions(){};
Transactions::~Transactions(){};

bool Transactions::openAccount(BSTree &tree, const string lastName, const string firstName, const int accountId)
{
	BankAccount *newAccount = new BankAccount(lastName, firstName, accountId);
	tree.Insert(newAccount);
	return true;
}


//Deposits funds into given fund type from an account already retrieved from Banker.cpp
bool Transactions::deposit(BankAccount *&account, int fundType, int dollarAmount, string transaction)
{
	account->funds[fundType].depositMoney(dollarAmount);
	addToHistory(account, fundType, transaction);
	return true;
}


//Withdraws funds from given fund type from an account already retrieved from Banker.coo
bool Transactions::withdraw(BankAccount *&account, int fundType, int dollarAmount, string transaction)
{
	// handles fund 0-3 for linked types
	if (fundType >= 0 && fundType <= 3) {
		// only enters if fund is between 0 and 3
		// Fund 0 linked with fund 1
		if (fundType == 0) {
			if (dollarAmount <= account->getSubAccBalance(fundType)) {
				account->funds[fundType].withdrawMoney(dollarAmount);
				addToHistory(account, fundType, transaction);
				return true;
			}
			if (dollarAmount <= (account->getSubAccBalance(fundType) + account->getSubAccBalance(1))) {
				int withdrawal = account->getSubAccBalance(fundType);
				int remainder = dollarAmount - withdrawal;
				account->funds[fundType].withdrawMoney(withdrawal);
				string txn1 = "W " + to_string(account->getID()) + to_string(fundType) + " " + to_string(withdrawal);
				addToHistory(account, fundType, txn1);
				account->funds[1].withdrawMoney(remainder);
				string txn2 = "W " + to_string(account->getID()) + to_string(1) + " " + to_string(remainder);
				addToHistory(account, 1, txn2);
				return true;
			}
			transaction = transaction + " (Failed)";
			addToHistory(account, fundType, transaction);
			return false;
		}
		// Fund 1 linked with fund 0
		if (fundType == 1) {
			if (dollarAmount <= account->getSubAccBalance(fundType)) {
				account->funds[fundType].withdrawMoney(dollarAmount);
				addToHistory(account, fundType, transaction);
				return true;
			}
			if (dollarAmount <= account->getSubAccBalance(fundType) + account->getSubAccBalance(0)) {
				int withdrawal = account->getSubAccBalance(fundType);
				int remainder = dollarAmount - withdrawal;
				account->funds[fundType].withdrawMoney(withdrawal);
				string txn1 = "W " + to_string(account->getID()) + to_string(fundType) + " " + to_string(withdrawal);
				addToHistory(account, fundType, txn1);
				account->funds[0].withdrawMoney(remainder);
				string txn2 = "W " + to_string(account->getID()) + to_string(1) + " " + to_string(remainder);
				addToHistory(account, 0, txn2);
				return true;
			}
			transaction = transaction + " (Failed)";
			addToHistory(account, fundType, transaction);
			return false;
		}
		// Fund 2 linked with fund 3
		if (fundType == 2) {
			if (dollarAmount <= account->getSubAccBalance(fundType)) {
				account->funds[fundType].withdrawMoney(dollarAmount);
				addToHistory(account, fundType, transaction);
				return true;
			}
			if (dollarAmount <= account->getSubAccBalance(fundType) + account->getSubAccBalance(3)) {
				int withdrawal = account->getSubAccBalance(fundType);
				int remainder = dollarAmount - withdrawal;
				account->funds[fundType].withdrawMoney(withdrawal);
				string txn1 = "W " + to_string(account->getID()) + to_string(fundType) + " " + to_string(withdrawal);
				addToHistory(account, fundType, txn1);
				account->funds[3].withdrawMoney(remainder);
				string txn2 = "W " + to_string(account->getID()) + to_string(3) + " " + to_string(remainder);
				addToHistory(account, 3, txn2);
				return true;
			}
			transaction = transaction + " (Failed)";
			addToHistory(account, fundType, transaction);
			return false;
		}
		// Fund 3 linked with fund 2
		if (fundType == 3) {
			if (dollarAmount <= account->getSubAccBalance(fundType)) {
				account->funds[fundType].withdrawMoney(dollarAmount);
				addToHistory(account, fundType, transaction);
				return true;
			}
			if (dollarAmount <= account->getSubAccBalance(fundType) + account->getSubAccBalance(2)) {
				int withdrawal = account->getSubAccBalance(fundType);
				int remainder = dollarAmount - withdrawal;
				account->funds[fundType].withdrawMoney(withdrawal);
				string txn1 = "W " + to_string(account->getID()) + to_string(fundType) + " " + to_string(withdrawal);
				addToHistory(account, fundType, txn1);
				account->funds[2].withdrawMoney(remainder);
				string txn2 = "W " + to_string(account->getID()) + to_string(2) + " " + to_string(remainder);
				addToHistory(account, 2, txn2);
				return true;
			}
			transaction = transaction + " (Failed)";
			addToHistory(account, fundType, transaction);
			return false;
		}
	}

	// funds 4-9
	if (dollarAmount > account->getSubAccBalance(fundType)) {
			transaction = transaction + " (Failed)";
			addToHistory(account, fundType, transaction);
			return false;
	}
	account->funds[fundType].withdrawMoney(dollarAmount);
	addToHistory(account, fundType, transaction);
	return true;
}


//Transfers funds between funds utilizing deposit and withdraw functions
bool Transactions::transfer(BankAccount *&accountOne, int accountOneFund, BankAccount *&accountTwo, int accountTwoFund, int dollarAmount, string transaction)
{
	
	if (withdraw(accountOne, accountOneFund, dollarAmount, transaction)) {
		deposit(accountTwo, accountTwoFund, dollarAmount, transaction);
		return true;
	}
	return false;
}


//Adds the transaction string to indidivdual funds 
bool Transactions::addToHistory(BankAccount *&accountId, int fundType, string transaction)
{
	accountId->funds[fundType].addToHistory(transaction);
	return true;
}
