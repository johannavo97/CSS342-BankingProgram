// Transactions.cpp
// Created by Chris Jensen
// Created on December 9, 2022
// Last Edited December 11, 2022
// A part of Program5 JollyBanker

#include "Transactions.h"
	//Gathers account information from banker and creates account instance which is inserted into BSTree
bool Transactions::openAccount(BSTree::Node* headNode, const string lastName, const string firstName, const int accountId)
{
	BSTree accountBST = new BSTree;
	accountBST.Insert(headNode);
	BankAccount* current = nullptr;
	if (accountBST.Retrieve(accountId, current))
	{
		//error message should be written to outfile account is already open
		return false;
	}
	BankAccount newAccount = new BankAccount(lastName, firstName, accountId);
	accountBST.Insert(newAccount);
	return true;
}


//Deposits funds into given fund type from an account already retrieved from Banker.cpp
bool Transactions::deposit(BankAccount* account, int fundType, int dollarAmount)
{
	account->funds[fundType].addMoney(dollarAmount);
	string transaction = "D " + account->getID() + fundType + " " + dollarAmount;
	addToHistory(account, fundType, transaction);
	return true;
}


//Withdraws funds from given fund type from an account already retrieved from Banker.coo
bool Transactions::withdraw(BankAccount* account, int fundType, int dollarAmount)
{
	string transaction = "W " + account->getID + fundType + " " + dollarAmount;
	// handles fund 0-3 for linked types
	if (fundType >= 0 && fundType <= 3) {
		// only enters if fund is between 0 and 3
		// Fund 0 linked with fund 1
		if (fundType == 0) {
			if (dollarAmount <= account->getSubAccBalance(fundType)) {
				account->funds[fundType].subtractMoney(dollarAmount);
				addToHistory(account, fundType, transaction);
				return true;
			}
			if (dollarAmount <= (account->getSubAccBalance(fundType) + account->getSubAccBalance(1))) {
				int remainder = dollarAmount - account->getSubAccBalance(fundType);
				account->funds[fundType].subtractMoney(account->getSubAccBalance(fundType));
				account->funds[1].subtractMoney(remainder);
				addToHistory(account, fundType, transaction);
				return true;
			}
			transaction = transaction + " (failed)";
			addToHistory(account, fundType, transaction);
			return false;
		}
		// Fund 1 linked with fund 0
		if (fundType == 1) {
			if (dollarAmount <= account->getSubAccBalance(fundType)) {
				account->funds[fundType].subtractMoney(dollarAmount);
				addToHistory(account, fundType, transaction);
				return true;
			}
			if (dollarAmount <= account->getSubAccBalance(fundType) + account->getSubAccBalance(0)) {
				int remainder = dollarAmount - account->getSubAccBalance(fundType);
				account->funds[fundType].subtractMoney(account->getSubAccBalance(fundType));
				account->funds[0].subtractMoney(remainder);
				addToHistory(account, fundType, transaction);
				return true;
			}
			transaction = transaction + " (failed)";
			addToHistory(account, fundType, transaction);
			return false;
		}
		// Fund 2 linked with fund 3
		if (fundType == 2) {
			if (dollarAmount <= account->getSubAccBalance(fundType)) {
				account->funds[fundType].subtractMoney(dollarAmount);
				addToHistory(account, fundType, transaction);
				return true;
			}
			if (dollarAmount <= account->getSubAccBalance(fundType) + account->getSubAccBalance(3)) {
				int remainder = dollarAmount - account->getSubAccBalance(fundType);
				account->funds[fundType].subtractMoney(account->getSubAccBalance(fundType));
				account->funds[3].subtractMoney(remainder);
				addToHistory(account, fundType, transaction);
				return true;
			}
			transaction = transaction + " (failed)";
			addToHistory(account, fundType, transaction);
			return false;
		}
		// Fund 3 linked with fund 2
		if (fundType == 3) {
			if (dollarAmount <= account->getSubAccBalance(fundType)) {
				account->funds[fundType].subtractMoney(dollarAmount);
				addToHistory(account, fundType, transaction);
				return true;
			}
			if (dollarAmount <= account->getSubAccBalance(fundType) + account->getSubAccBalance(2)) {
				int remainder = dollarAmount - account->getSubAccBalance(fundType);
				account->funds[fundType].subtractMoney(account->getSubAccBalance(fundType));
				account->funds[2].subtractMoney(remainder);
				addToHistory(account, fundType, transaction);
				return true;
			}
			transaction = transaction + " (failed)";
			addToHistory(account, fundType, transaction);
			return false;
		}
	}

	// funds 4-9
	if (dollarAmount > account->getSubAccBalance(fundType)) {
		return false;
	}
	account->funds[fundType].subtractMoney(dollarAmount);
	addToHistory(account, fundType, transaction);
	return true;
}


//Transfers funds between funds utilizing deposit and withdraw functions
bool Transactions::transfer(BankAccount* accountOne, int accountOneFund, BankAccount* accountTwo, int accountTwoFund, int dollarAmount)
{
	if (withdraw(accountOne, accountOneFund, dollarAmount)) {
		deposit(accountTwo, accountTwoFund, dollarAmount);
		string transaction = "T " + accountOne->getID() + accountOneFund + " " + dollarAmount;
		addToHistory(account, fundType, transaction);
		return true;
	}

	return false;
}


//Adds the transaction string to indidivdual funds 
bool Transactions::addToHistory(BankAccount* accountId, int fundType, string transaction)
{
	accountId->funds[fundType].addToHistory(transaction);
	return true;
}
