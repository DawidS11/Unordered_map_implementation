#include <iostream>
#include <cassert>

#include "UnorderedMap.hpp"

int main()
{
    UnorderedMap m;

    assert(m.empty() == true);
    assert(m.size() == 0);

    m.emplace(0, "zero");
    m.emplace(1, "one");
    m.emplace(2, "two");
    m.try_emplace(2, "two");
    m.insert(std::make_pair<int, std::string>(3, "three"));
    m.emplace(997, "aaa");
    m.emplace(998, "bbb");
    m.emplace(999, "ccc");
    m.emplace(1000, "ddd");
    m.emplace(55, "eee");
    m.insert(std::make_pair<int, std::string>(3, "xxx3"));
    m.insert(std::make_pair<int, std::string>(151, "xxx151"));
    m.insert(std::make_pair<int, std::string>(152, "xxx152"));
    m.insert(std::make_pair<int, std::string>(153, "xxx153"));
    m.insert(std::make_pair<int, std::string>(154, "xxx154"));

    m.remove(55);
    m.remove(154);

    assert(m.find(0) == "zero");
    assert(m.find(2) == "two");
    assert(m.find(10) == std::string{});
    assert(m.find(3) == "xxx3");

    assert(m.find(1) == "one");
    assert(m[1] == "one");
    assert(m[3] == "xxx3");
    m[10] = "ten";
    assert(m.find(10) == "ten");
    m[1] = "qqq";
    assert(m.find(1) == "qqq");
    assert(m[1] == "qqq");

    assert(m.contains(55) == false);
    assert(m.contains(154) == false);
    assert(m.contains(2) == true);
    assert(m.contains(5) == false);

    assert(m.empty() == false);
    assert(m.size() == 12);

    m.print();
}