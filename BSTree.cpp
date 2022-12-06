#include "BSTree.h"
#include <fstream>

BSTree::BSTree() { root = nullptr; }
BSTree::~BSTree() { clear(root); }

// Insert a new account
bool BSTree::Insert(BankAccount *accInsert)
{
    int insertAccountID = accInsert->getID();
    if (insertAccountID < 1000 || insertAccountID > 9999)
    {
        cerr << "ERROR: Account ID Number Not Valid" << endl;
        return false;
    }

    if (root == NULL)
    {
        root = new Node;
        root->pAcct = accInsert;
        root->left = NULL;
        root->right = NULL;
        return true;
    }
    else
    {
        Node *current = root;
        InsertHelper(current, accInsert);
    }
    return false;
}

bool BSTree::Retrieve(const int &id, BankAccount *&acc) const
{
    Node *current = root;
    bool search = false;

    while (!search)
    {
        if (current != NULL && id == current->pAcct->getID())
        {
            search = true;
            acc = current->pAcct;
            return search;
        }
        else if (current != NULL && id > current->pAcct->getID())
        {
            current = current->right;
        }
        else if (current != NULL && id < current->pAcct->getID())
        {
            current = current->left;
        }
        else
        {
            search = true;
        }
    }
    cerr << "ERROR: Account Number " << id << " Cannot Be Found" << endl;
    return false;
}


void BSTree::Empty()
{
    delete root;
    root = nullptr;
}

bool BSTree::isEmpty() const
{
    if (root->left == nullptr && root->right == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BSTree::Display() const
{
    if (root == nullptr)
    {
        cerr << "ERROR: ACCOUNT LIST IS EMPTY" << endl;
    }
    PrintHelper(root);
}

void BSTree::PrintHelper(Node *current) const{
    if (current != nullptr) {
        PrintHelper(current->left);

        ofstream outfile;
        outfile.open("BankTransOut.txt", std::ios_base::app);

        outfile << current->pAcct->getLastName() << " ";
        outfile << current->pAcct->getFirstName();
        outfile << " Account ID: ";
        outfile << current->pAcct->getID() << endl;

        for (int i = 0; i < 10; i++) {
            outfile << "        " << current->pAcct->getSubAccName(i)
                    << ": $" << current->pAcct->getSubAccBalance(i)
                    << endl;
        }
        outfile << endl;
        PrintHelper(current->right);
        outfile.close();
    }
}

bool BSTree::InsertHelper(Node *current, BankAccount *insert)
{
    if (insert->getID() > current->pAcct->getID())
    {
        if (current->right == NULL)
        {
            Node *insInTree = new Node();
            insInTree->pAcct = insert;
            insInTree->left = NULL;
            insInTree->right = NULL;
            current->right = insInTree;
            return true;
        }
        else
        {
            return InsertHelper(current->right, insert);
        }
    }
    else if (insert->getID() < current->pAcct->getID())
    {
        if (current->left == NULL)
        {
            Node *insInTree = new Node();
            insInTree->pAcct = insert;
            insInTree->left = NULL;
            insInTree->right = NULL;
            current->left = insInTree;
            return true;
        }
        else
        {
            return InsertHelper(current->left, insert);
        }
    }
    else
    {
        cerr << "ERROR: Account " << insert->getID() << " is already open. Transaction refused." << endl;
        return false;
    }
}

// delete all information in BSTree
void BSTree::clear(Node *node)
{
    if (node != nullptr)
    {
        clear(node->left);
        clear(node->right);
        // delete accounts and nodes
        delete node->pAcct;
        delete node;
    }
}