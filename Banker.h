// Testing this structure?
//
//
//

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
		BSTree accounts;
		queue<string> txns;
		Transactions processor;
	public:
		Banker();
		~Banker();

		bool readTransactionsFromFile(string fileName);
		void processTransactions();
		void printOutBalances();

		int getIDs(int &id);
};
