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
#include "Banker.h"
using namespace std;

Banker::Banker() {}
Banker::~Banker() {}

int Banker::getIDs(int &id);

bool Banker::readTransactionsFromFile(string fileName)
{
    string temp;
    ifstream inFile;
    inFile.open(fileName);
    if(inFile.is_open())
    {

        while(!inFile.eof())
        {
            getline(inFile, temp);
            txns.push(temp);
        }
        inFile.close();
    }
    else 
    {
        cout << "File: " << fileName << " not found.";
    }
    return true;
}

// =========================================== TO DO ======================================

bool Banker::processTransactions()
{
//       Will process all transactions in the queue
	
	
// 	string temp;
// 	while(!txns.empty())
// 	{
// 		temp = txns.front();
// 		x.pop();
// 		stringstream s(temp);
// 		string a;
// 		s >> a;
// 		if(a=="O")
// 		{
// 		}
// 		else if(a == "D")
//		{
//		}
// 	}                          
}

// =========================================== TO DO ======================================

bool Banker::printOutBalances()
{
	//      Will print out all account balances
}

// =================================== Helper Functions ===================================

int Banker::getIDs(int &id)
{
    int temp = id;
    id/=10;
    return temp%10;
}
