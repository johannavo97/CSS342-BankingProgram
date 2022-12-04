#pragma once
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class BSTree
{
	public:
		BSTree();
		~BSTree();

		bool Insert(Account *acc);

		bool Retrieve(const int &id, Account * &acc) const;

		void Display() const;
		void Empty();
		bool isEmpty() const;

	private:
		struct Node
		{
			Account *pAcct;
			Node *right;
			Node *left;
		};
		Node *root;
};