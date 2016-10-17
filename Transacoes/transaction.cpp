#include "transaction.h"


Transaction::Transaction()
{

}

Transaction::Transaction(string name)
{
    this->name = name;
}

string Transaction::getName()
{
    return name;
}
void Transaction::setName(string name)
{
    this->name = name;
}

