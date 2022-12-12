// William Bach
// CSS342 Fall22
// Program 5 - Jolly Banker
#pragma once
#include <iostream>
#include <queue>
#include <string>
#include "BSTree.h"
#include "BSTree.cpp"
#include "Transactions.h"
#include "Transaction.cpp"
using namespace std;

class Banker
{
	private:
		BSTree accounts; // Binary search tree where accounts will be stored
		queue<string> txns; // Queue of transactions strings
		// Private instance of transactions class to process account openings, desposits, withdrawals and transfers
		Transactions processor; 
	public:
		Banker();
		~Banker();

		bool readTransactionsFromFile(string fileName);
		void processTransactions();
		void printOutBalances();

		int getIDs(int &id);
};
