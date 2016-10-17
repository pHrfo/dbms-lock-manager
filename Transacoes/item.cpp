#include "item.h"

Item::Item(string name)
{
    id = name;
}

string Item::getId()
{
    return id;
}

Lock Item::getLock()
{
    return lock;
}

bool Item::isLocked()
{
    if (lock.getLockState() == 0)
        return false;
    else
        return true;
}

bool Item::isLockedRead()
{
    if (lock.getLockState() <= 1)
        return false;
    else
        return true;
}

bool Item::isLockedWrite()
{
    if (isLocked())
        return true;
    else
        return false;
}

void Item::addReadLock(Transaction t)
{
    if ((!isLockedRead()) && (queue.isEmpty()))
    {
        lock.addLockingTransaction(t);
        if (lock.getLockState() == 0)
            lock.setLockState(1);
    }
    else
    {
        queue.insert(t,1);
    }
}

void Item::addWriteLock(Transaction t)
{
    if (!isLockedWrite())
    {
        lock.addLockingTransaction(t);
        lock.setLockState(2);
    }
    else
    {
        queue.insert(t,2);
    }
}

void Item::unlock(Transaction t)
{
    if (isLocked())
    {
        lock.removeLockingTransaction(t);
        if (lock.getNumberOfTransactions() == 0)
        {
            lock.setLockState(0);
        }
    }
}
