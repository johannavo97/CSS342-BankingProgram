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

int Banker::getIDs(int &id);

bool Banker::ReadTXNsFromFile(string fileName)
{
    string temp;
    ifstream inFile;
    inFile.open(fileName);
    if(inFile.is_open())
    {

        while(!inFile.eof())
        {
            getline(inFile, temp);
            txns.push(t);
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
