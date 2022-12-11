//Driver.cpp
//Group Random Driver Code
#include "Banker.h"


int main()
{
    Banker b;
    b.readTransactionsFromFile("BankTransIn.txt");
    b.processTransactions();
    b.printOutBalances();

    return 0;
}
