#ifndef UNORDERED_MAP_HPP
#define UNORDERED_MAP_HPP

#include <iostream>
#include <list>
#include <string>

class UnorderedMap
{
private:
    static const int hashGroups = 10;
    std::list<std::pair<int, std::string>> hashTable[hashGroups];

public:
    int hashFunction(const int key) const;
    int size() const;
    bool empty() const;
    bool contains(const int key) const;
    std::string find(const int key) const;
    void emplace(const int key, const std::string& value);
    void try_emplace(const int key, const std::string& value);

    void print() const;
};

#endif