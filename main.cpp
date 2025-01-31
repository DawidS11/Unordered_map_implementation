#include <iostream>
#include "UnorderedMap.hpp"

int main()
{
    UnorderedMap m;

    m.emplace(1, "one");
    m.emplace(2, "two");
    m.try_emplace(2, "two");

    m.print();

    std::cout << m.find(2) << std::endl;
    std::cout << m.contains(3) << std::endl;
}