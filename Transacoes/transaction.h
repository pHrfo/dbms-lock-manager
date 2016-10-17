#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "general.h"

class Transaction
{
private:
    string name;

public:
    Transaction();
    Transaction(string);
    string getName();
    void setName(string);
};

#endif // TRANSACTION_H
