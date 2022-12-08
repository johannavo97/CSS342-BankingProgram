// Testing this structure?
//
//
//

#pragma once
#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include "BSTree.h"
#include "Transaction.h"
using namespace std;

class Banker
{
	public:
		Banker();
		~Banker();

		bool readTransactionsFromFile();
		bool processTransactions();
		bool printOutBalances();

		int getIDs(int &id);

	private:
		BSTree accounts;
		queue<string> txns;

};
