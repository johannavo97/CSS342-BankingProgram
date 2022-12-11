// Funds.h
// Minseong Na
// Created on 12-07-22
// A part of Program 5 Jolly Banker

#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include "Transactions.h"

using namespace std;

class Funds
{
    public:

        Funds();
        Funds(string name);
        Funds(string name, int balance);
        ~Funds();

        string getFundName() const;
        int getBalance() const;
        void setFundName(string name1);
        void setBalance(int balance1);

        bool addMoney(int amt);
        bool subtractMoney(int amt);
        bool addToHistory(string txn);
        void printFundHistory();
        

    private:

        string name;
        int balance;
        vector<string> history;


};