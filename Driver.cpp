//Driver.cpp
//Group Random Driver Code
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Banker.h"
#include "Banker.cpp"
using namespace std;


int main()
{
    Banker b;
    b.readTransactionsFromFile("BankTransIn.txt");
    b.processTransactions();
    b.printOutBalances();
    return 0;
}
