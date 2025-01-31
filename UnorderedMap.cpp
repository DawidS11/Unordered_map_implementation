#include "UnorderedMap.hpp"

#include <algorithm>

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
        if (!hashTable[i].empty())
        {
            return false;
        }
    }
    return true;
}

bool UnorderedMap::contains(const int key) const
{
    int hashKey = hashFunction(key);
    if (std::find_if(
        hashTable[hashKey].begin(), hashTable[hashKey].end(),
        [&key](const std::pair<int, std::string>& x) { return x.first == key; }) != hashTable[hashKey].end())
    {
        return true;
    }
    return false;
}

std::string UnorderedMap::find(const int key) const
{
    int hashKey = hashFunction(key);
    auto it = std::find_if(
        hashTable[hashKey].begin(), hashTable[hashKey].end(),
        [&key](const std::pair<int, std::string>& x) { return x.first == key; });
    if (it != hashTable[hashKey].end())
    {
        return it->second;
    }
    return std::string{};
}

void UnorderedMap::emplace(const int key, const std::string& value)
{
    int hashKey = hashFunction(key);
    auto it = std::find_if(
        hashTable[hashKey].begin(), hashTable[hashKey].end(),
        [&key](const std::pair<int, std::string>& x) { return x.first == key; });
    if (it != hashTable[hashKey].end())
    {
        it->second = value;
        return;
    }

    hashTable[hashKey].emplace_back(key, value);
}

void UnorderedMap::try_emplace(const int key, const std::string& value)
{
    int hashKey = hashFunction(key);
    auto it = std::find_if(
        hashTable[hashKey].begin(), hashTable[hashKey].end(),
        [&key](const std::pair<int, std::string>& x) { return x.first == key; });
    if (it != hashTable[hashKey].end())
    {
        return;
    }

    hashTable[hashKey].emplace_back(key, value);
}

void UnorderedMap::print() const
{
    for (int i = 0; i < hashGroups; ++i)
    {
        for (auto it = hashTable[i].begin(); it != hashTable[i].end(); ++it)
        {
            std::cout << it->first << ", " << it->second << std::endl;
        }
        std::cout << std::endl;
    }
}