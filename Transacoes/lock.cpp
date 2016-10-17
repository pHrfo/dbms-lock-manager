#include "lock.h"

Lock::Lock()
{
    lockState = 0;
}

void Lock::setLockState(int state)
{
    lockState = state;
}

int Lock::getLockState()
{
    return lockState;
}

int Lock::getNumberOfTransactions()
{
    return lockingTransaction.size();
}

void Lock::addLockingTransaction(Transaction t)
{
    lockingTransaction.push_back(t);
}

void Lock::removeLockingTransaction(Transaction t)
{
    int pos;
    for (int i=0; i<lockingTransaction.size(); i++)
    {
        if (lockingTransaction.at(i).getName() == t.getName())
        {
            pos = i;
        }
    }
    lockingTransaction.erase(lockingTransaction.begin() + pos);
}
