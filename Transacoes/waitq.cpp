#include "waitq.h"

waitQ::waitQ()
{

}

void waitQ::insert(Transaction t, int i)
{
    queueType k;
    k.lockType = i;
    k.t = t;
    q.push_back(k);
}

Transaction waitQ::getNextTransaction()
{
    Transaction t;
    t = q.at(0).t;
    q.erase(q.begin());
    return t;
}

bool waitQ::isEmpty()
{
    if (q.size() == 0)
        return true;
    else
        return false;
}
