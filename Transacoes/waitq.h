#ifndef WAITQ_H
#define WAITQ_H

#include "transaction.h"

struct queueType {
    int lockType;
    Transaction t;
};

class waitQ
{
private:
    vector<queueType> q;
public:
    waitQ();

    void insert(Transaction, int);
    Transaction getNextTransaction();
    bool isEmpty();
};

#endif // WAITQ_H
