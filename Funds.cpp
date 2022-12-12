#include "Funds.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
using namespace std;

Funds :: Funds()
{
    name = " ";
    balance = 0;
}

Funds :: Funds(string name1)
{
    name = name1;
    balance = 0;
}

Funds :: Funds(string name1, int balance1)
{
    name = name1;
    balance = balance1;
}

Funds :: ~Funds() {}

string Funds :: getFundName() const
{
    return name;
}

int Funds :: getBalance() const
{
    return balance;
}

void Funds :: setFundName(string name1)
{
    name = name1;
}

void Funds :: setBalance(int balance1)
{
    balance = balance1;
}

bool Funds :: depositMoney(int amt)
{
    balance += amt;
    return true;
}

bool Funds :: withdrawMoney(int amt)
{
    balance -= amt;
    return true;
}

bool Funds::withdrawPossible(int amount)
{
	if(balance < amount)
	{
		return false;
	}
	return true;
}

bool Funds :: addToHistory(string txn)
{
    history.push_back(txn);
    return true;
}


void Funds :: printFundHistory()
{
    if(history.size() > 0)
    {
        ofstream outfile;
        outfile.open("BankTransOut.txt", std::ios_base::app);
        outfile << name << ": $" << balance << "\n";
        for(int i = 0; i < history.size(); i++)
        {
            outfile << " " << history[i] << endl;
        }
        outfile.close();
    }
        
}

