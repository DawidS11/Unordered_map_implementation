#include <iostream>
#include <list>
#include <string>

class UnorderedMap
{
public:
    int size() const;
    bool empty() const;

private:
    static const int hashGroups = 10;
    std::list<std::pair<int, std::string>> hashTable[hashGroups];
};

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