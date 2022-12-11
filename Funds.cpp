#include "Funds.h"


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

bool Funds :: addMoney(int amt)
{
    balance += amt;
    return true;
}

bool Funds :: subtractMoney(int amt)
{
    if(amt > balance)
    {
        return false;
    }else{
        balance -= amt;
        return true;
    }
    

}

bool Funds :: addToHistory(string txn)
{
    history.push_back(txn);
    return true;
}

// bool Fund::addToHistoryWithError(string txn)  // Placeholder. I think we need to need to include failed transactions in history too
// {
// 	string temp = txn + " (Failed)";
// 	history.push_back(temp);
// 	return true;
// }

void Funds :: printFundHistory()
{
    if(history.size() <= 0)
    {
        cout << "No history" << endl;
    }else{
        for(int i = 0; i < history.size(); i++)
        {
            cout << history[i] << endl;
        }
    }
        
}

