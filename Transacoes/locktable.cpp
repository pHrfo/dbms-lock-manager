#include "locktable.h"

LockTable::LockTable()
{

}

void LockTable::addItem(Item i)
{
    itemList.push_back(i);
}

Item LockTable::getItem(string id)
{
    Item i("Not Found");
    for (unsigned int k=0; k<itemList.size(); k++)
    {
        if (itemList.at(k).getId() == id)
        {
            return itemList.at(k);
        }
    }
    return i;
}
