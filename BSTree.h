#pragma once
#include "BankAccount.h"
using namespace std;

class BSTree
{
	public:
		BSTree();
		~BSTree();

		bool Insert(BankAccount *acc);

		bool Retrieve(const int &id, BankAccount * &acc) const;

		void Display() const;
		void Empty();
		bool isEmpty() const;

	private:
		struct Node
		{
			BankAccount *pAcct;
			Node *right;
			Node *left;
		};
		Node *root;
		// delete all information in BSTree
		void clear(Node* node)
};
