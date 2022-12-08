// Funds.h
// Minseong Na
// Created on 12-07-22
// A prat of Program 5 Jolly Banker

#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

class Funds
{
    public:
        int getFundType();
        int getBalance();
        void setFundType(string FundType);
        void setBalance(int amt);

        addMoney(int amt);
        subtractMoney(int amt);
        addToHistory(string txn);
        addToHistoryWithError(string txn);
        printFundHistory();
        bool withdrawPossible(int amt);

    private:

        string fundType;
        int balance;
        string history[];


};