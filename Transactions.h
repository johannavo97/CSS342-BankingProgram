// Transactions.h
// Created by Chris Jensen
// Created on December 6, 2022
// A part of Program5 JollyBanker

#pragma once
#include <iostream>
#include <cmath>
#include <queue>
#include <string>
#include "Funds.h"
#include "BankAccount.h"
using namespace std;

class Transactions
{
public:
	bool openAccount(const string lastName, const string firstName, const int accountId);
	bool withdraw(int accountId, Funds fundType, int dollarAmount);
	bool transfer(int accountIdOne, Funds accountOneFund, int dollarAmount, int accountIdtwo, Funds accountTwoFund);
	bool history(int accountId);
};