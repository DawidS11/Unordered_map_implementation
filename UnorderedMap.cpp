#include "UnorderedMap.hpp"

int UnorderedMap::hashFunction(const int key) const
{
    return key % hashGroups;
}

int UnorderedMap::size() const
{
    int sum = 0;
    for (int i = 0; i < hashGroups; ++i)
    {
        sum += hashTable[i].size();
    }
    return sum;
}

bool UnorderedMap::empty() const
{
    for (int i = 0; i < hashGroups; ++i)
    {
        if (hashTable[i].size())
        {
            return false;
        }
    }
    return true;
}