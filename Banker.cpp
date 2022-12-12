// William Bach
// CSS342 Fall22
// Program 5 - Jolly Banker
#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <string>
#include "Banker.h"
#include "BankAccount.h"
#include "BSTree.h"
#include "Transactions.h"
using namespace std;

Banker::Banker() {}
Banker::~Banker() {}

int Banker::getIDs(int &id) //converts 5 digit ID to account and fund IDs.
{
    int temp = id;
    id/=10;
    return temp%10;
}

bool Banker::readTransactionsFromFile(string fileName)
{
    // Reads transactions in the input file and stores them as strings in the queue
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

void Banker::processTransactions()
{
//  Parses and processes all transactions in the queue
	string transaction;
	while(!txns.empty())
	{
		transaction = txns.front();
		txns.pop();
		stringstream s(transaction);
		string typeOfTxn;
		s >> typeOfTxn;
		if(typeOfTxn=="O")
		{
			int id;
			string last, first;
			s >> last >> first >> id;
			processor.openAccount(accounts, last, first, id);

		}
		else if(typeOfTxn == "D")
		{
			int id, fundID, amount;
			s >> id >> amount;
			fundID = getIDs(id);
			BankAccount *bAcc;
			if(accounts.Retrieve(id, bAcc))
			{
				processor.deposit(bAcc, fundID, amount, transaction);
			}
		}
		else if(typeOfTxn == "W")
		{
			int id, fundID, amount;
			s >> id >> amount;
			fundID = getIDs(id);
			BankAccount *bAcc;
			if(accounts.Retrieve(id, bAcc))
			{
				processor.withdraw(bAcc, fundID, amount, transaction);
			}
		}
		else if(typeOfTxn == "T")
		{
			int id1, fund1, amount, id2, fund2;
			s >> id1 >> amount >> id2;
			fund1 = getIDs(id1);
			fund2 = getIDs(id2);
			BankAccount *bAcc1, *bAcc2;
			if(id1!=id2)
			{
				if(accounts.Retrieve(id1, bAcc1) && accounts.Retrieve(id2, bAcc2))
				{
					bool transferPossible = processor.withdraw(bAcc1, fund1, amount, transaction);
					if(transferPossible)
					{
						processor.deposit(bAcc2, fund2, amount, transaction);
					}
				}
			}
			else
			{
				if(accounts.Retrieve(id1, bAcc1))
				{
					processor.transfer(bAcc1, fund1, bAcc1, fund2, amount, transaction);
				}
			}
		}
		else if(typeOfTxn == "H")
		{
			int id;
			s >> id;
			BankAccount *bAcc;
            if(id<10000)
            {
                if(accounts.Retrieve(id, bAcc))
                {
                    bAcc->printAccountHistory();
                }
            }
            else{
                int fundID = getIDs(id);
                if(accounts.Retrieve(id, bAcc))
                {
                    bAcc->printSingleFundHistory(fundID);
                }
            }
		}
	}                          
}

// =======================================================================================

void Banker::printOutBalances()
{
	// Prints out all account balances
   	ofstream outfile;
	outfile.open("BankTransOut.txt", std::ios_base::app);
	outfile << "\nProcessing Done. Final Balances.\n";
    	outfile.close();
	accounts.Display();
}

