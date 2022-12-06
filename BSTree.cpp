#include "BSTree.h"
#include <fstream>

BSTree::BSTree(){ root = nullptr;}
BSTree::~BSTree(){clear(root);}

//Insert a new account
bool BSTree::Insert(BankAccount *acc){

}

bool BSTree::Retrieve(const int &id, BankAccount * &acc) const{
    
}
// delete all information in BSTree
void BSTree::clear(Node* node){
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        // delete accounts and nodes
        delete node->pAcct;
        delete node;
    }

}