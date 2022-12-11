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
#include "Transactions.h"
#include "BankAccount.h"
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

// // =================================================================================

// void Banker::processTransactions()
// {
// //  Processes all transactions in the queue
	
	
// 	string transaction;
// 	while(!txns.empty())
// 	{
// 		transaction = txns.front();
// 		txns.pop();
// 		stringstream s(transaction);
// 		string typeOfTxn;
// 		s >> typeOfTxn;
// 		if(typeOfTxn=="O")
// 		{
// 			int id;
// 			string last, first;
// 			s >> last >> first >> id;
// 			BankAccount *bAcc(last, first, id);
// 			accounts.Insert(bAcc);

// 		}
// 		else if(typeOfTxn == "D")
// 		{
// 			int id, fundID, amount;
// 			s >> id >> amount;
// 			fundID = getIDs(id);
// 			BankAccount *bAcc;
// 			if(accounts.Retrieve(id, bAcc))
// 			{
// 				bAcc->deposit(amount, fundID, transaction);
// 			}
// 		}
// 		else if(typeOfTxn == "W")
// 		{
// 			int id, fundID, amount;
// 			s >> id >> amount;
// 			fundID = getIDs(id);
// 			BankAccount *bAcc;
// 			if(accounts.Retrieve(id, bAcc))
// 			{
// 				bAcc->deposit(amount, fundID, transaction);
// 			}
// 		}
// 		else if(typeOfTxn == "T")
// 		{
// 			int id1, fund1, amount, id2, fund2;
// 			s >> id1 >> amount >> id2;
// 			fund1 = getIDs(id1);
// 			fund2 = getIDs(id2)
// 			BankAccount *bAcc1, *bAcc2;
// 			if(id1!=id2)
// 			{
// 				if(accounts.Retrieve(id1, bAcc1) && accounts.Retrieve(id2, bAcc2))
// 				{
// 					bool transferPossible = bAcc1.withdraw(amount, fund1, transaction);
// 					if(TransferPossible)
// 					{
// 						bAcc2->deposit(amount, fund2, transaction);
// 					}
// 				}
// 			}
// 			else
// 			{
// 				if(accounts.Retrieve(id1, bAcc1))
// 				{
// 					bAcc1->transferFunds(fund1, amount, fund2, transaction)
// 				}
// 			}
// 		}
// 		else if(typeOfTxn == "H")
// 		{
// 			int id;
// 			s >> id;
// 			BankAccount *bAcc;
// 			if(accounts.Retrieve(id, bAcc))
// 			{
// 				bAcc->printAccountHistory();
// 			}
// 		}
// 	}                          
// }

// // =======================================================================================

// bool Banker::printOutBalances()
// {
// 	// Prints out all account balances

// 	cout << "Processing Done. Final Balances\n";
// 	accounts.Display();
// }

// // =================================== Helper Functions ===================================

int Banker::getIDs(int &id)
{
    int temp = id;
    id/=10;
    return temp%10;
}
