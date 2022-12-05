#pragma once
#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include "BSTree.h"
#include "Transaction.h"
#include "Banker.h"
using namespace std;

int Banker::getIDs(int &id);

bool Banker::ReadTXNsFromFile(string fileName)
{
    ifsteam inFile;
    inFile.open(fileName);
    if(inFile.is_open())
    {
        while(!inFile.eof())
        {

            string txntype;
            inFile >> txntype;

            if(txntype=="O")
            {
            	int id;
            	string last, first;
            	inFile >> last >> first >> id;
            	Transaction txn(txntype, last, first, id);
            	txns.push(txn);
            }
            else if(txntype=="W")
            {
            	int id, fund, amt;
            	inFile >> id >> amt;
            	fund=getIDs(id);
            	Transaction txn(txntype, id, fund, amt);
            	txns.push(txn);
            }
            else if(txntype=="D")
            {
            	int id, fund, amt;
            	inFile >> id >> amt;
            	fund=getIDs(id);
            	Transaction txn(txntype, id, fund, amt);
            	txns.push(txn);
            }
            else if(txntype=="T")
            {
            	int id1, fund1, amt, id2, fund2;
            	inFile >> id1 >> amt >> id2;
            	fund1=getIDs(id1);
            	fund2=getIDs(id2);
            	Transaction txn(txntype, id1, fund1, amt, id2, fund2);
            	txns.push(txn);
            }
            else if(txntype=="H")
            {
            	int id, fund;
            	inFile >> id;

            	Transaction txn(txntype, id);
            	txns.push(txn);
            }

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

bool Banker::ProcessTXNs()
{
//       Will process all transactions in the queue
}

// =========================================== TO DO ======================================

bool Banker::PrintOutBalances()
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
