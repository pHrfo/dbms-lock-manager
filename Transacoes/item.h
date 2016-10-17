#ifndef ITEM_H
#define ITEM_H

#include "lock.h"
#include "general.h"
#include "waitq.h"

class Item
{
private:
    string id;
    Lock lock;
    waitQ queue;
public:
    Item(string);

    string getId();
    Lock getLock();

    bool isLocked();
    bool isLockedWrite();
    bool isLockedRead();

    void addWriteLock(Transaction);
    void addReadLock(Transaction);
    void unlock(Transaction);

};

#endif // ITEM_H
