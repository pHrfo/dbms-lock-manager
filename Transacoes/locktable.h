#ifndef LOCKTABLE_H
#define LOCKTABLE_H

#include "item.h"

class LockTable
{
private:
    vector <Item> itemList;
public:
    LockTable();
    void addItem(Item);
    Item getItem(string);
};

#endif // LOCKTABLE_H
