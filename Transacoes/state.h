#ifndef STATE_H
#define STATE_H

#include "general.h"
#include "transaction.h"

class State
{
public:
    vector<Transaction> transactions;

    State();

};
#endif // STATE_H
