#include "Funds.h"
#include <fstream>
#include <string>

using namespace std;

Funds :: Funds()
{
    fundType = " ";
    balance = 0;
}

Funds :: ~Funds() {}

Funds :: string getFundType() const
{
    return fundType;
}

Funds :: int getBalance() const
{
    return balance;
}

Funds :: void setFundType(string fundType1)
{
    fundType = fundType1;
}

Funds :: void setBalance(int balance1)
{
    balance = balance1;
}

Funds :: void addMoney(int amt)
{
    balance += amt;
}

Funds :: void subtractMoney(int amt)
{
    balance -= amt;
}

Funds :: void addToHistory(string txn)
{
    history += (txn += "\n");
}

Funds :: void addToHistoryWithError(string txn)
{
    history += (txn += "\n");
}

Funds :: void printHistory()
{
    //ofstream
}

Funds :: bool withdrawPossible(int atm)
{
    if(balance >= atm)
    {
        return true;
    }else{
        return false;
    }
    return false;
}