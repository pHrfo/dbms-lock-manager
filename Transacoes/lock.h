#ifndef LOCK_H
#define LOCK_H

#include "transaction.h"

class Lock
{
private:
    int lockState;
    vector<Transaction> lockingTransaction;
public:
    Lock();

    void setLockState(int);
    int getLockState();

    int getNumberOfTransactions();

    void addLockingTransaction(Transaction);
    void removeLockingTransaction(Transaction);
};

#endif // LOCK_H
