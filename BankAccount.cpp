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

void BankAccount::setLastName(string lname)
{
	this->lastname = lname;
}

void BankAccount::setFirstName(string fname)
{
	this->firstname = lname;
}

void BankAccount::setID(string newID)
{
	this->accountID = newID;
}
