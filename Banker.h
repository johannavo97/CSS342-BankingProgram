// Testing this structure?
//
//
//

#pragma once
#include <iostream>
#include <queue>
#include <string>
#include "BSTree.h"
#include "TransactionProcessing.h"
using namespace std;

class Banker
{
	private:
		BSTree accounts;
		queue<string> txns;
	public:
		Banker();
		~Banker();

		bool readTransactionsFromFile(string fileName);
		bool processTransactions();
		bool printOutBalances();

		int getIDs(int &id);
};
