#pragma once
#include <string>
#include <vector>
#include <utility>

/*
a hashmap that has strings as keys and ints as values
keys corresponding to a bucket are stored in a linked list
insertion is done at the beginning of the list
on access elements are moved to the beginning of the list
*/
class StringIntHashMap{
  public:
    StringIntHashMap(int);
    void insert(std::pair<std::string, int>);
    bool exists(std::string key);
    int get(std::string key);

    int size;
    unsigned int getHash(std::string);

};