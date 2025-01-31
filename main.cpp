#include <iostream>
#include "UnorderedMap.hpp"
#include <cassert>

int main()
{
    UnorderedMap m;

    assert(m.empty() == true);
    assert(m.size() == 0);
    m.emplace(1, "one");
    m.emplace(2, "two");
    m.try_emplace(2, "two");
    m.insert(std::make_pair<int, std::string>(3, "three"));

    m.print();

    assert(m.find(1) == "one");
    assert(m.find(2) == "two");
    assert(m.find(10) == std::string{});
    assert(m.find(3) == "three");
    assert(m.contains(2) == true);
    assert(m.contains(5) == false);
    assert(m.empty() == false);
    assert(m.size() == 3);
}