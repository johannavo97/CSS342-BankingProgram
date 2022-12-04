#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount() : last(""), first(""), id(0) {}

BankAccount::BankAccount(string last, string first, int id)
{
	this->lastname = last;
	this->firstname = first;
	this->accountID = id;
}

BankAccount::~BankAccount(){}

int BankAccount::getLastName() const
{
	return lastname;
}

int BankAccount::getFirstName() const
{
	return firstname;
}

int BankAccount::getLastName() const
{
	return accountID;
}

void BankAccount::setLastName(string last)
{
	this->lastname = last;
}

void BankAccount::setFirstName(string first)
{
	this->firstname = first;
}

void BankAccount::setID(string newID)
{
	this->accountID = newID;
}
