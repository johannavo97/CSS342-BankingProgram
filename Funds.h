// Funds.h
// Minseong Na
// Created on 12-07-22
// A part of Program 5 Jolly Banker

#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

class Funds
{
    public:

        Funds();
        ~Funds();

        string getFundType() const;
        int getBalance() const;
        void setFundType(string fundType1);
        void setBalance(int balance1);

        void addMoney(int amt);
        void subtractMoney(int amt);
        void addToHistory(string txn);
        void addToHistoryWithError(string txn);
        void printFundHistory();
        bool withdrawPossible(int amt);

    private:

        string fundType;
        int balance;
        string history[];


};