#pragma once
#include <string>
#include <vector>

/*
a hashmap that has strings as keys and ints as values
keys corresponding to a bucket are stored in a linked list
insertion is done at the beginning of the list
on access elements are moved to the beginning of the list
*/
class StringIntHashMap{
  public:
    StringIntHashMap(int);
    void insert(std::string key, int);
    bool exists(std::string key);
    int get(std::string key);

  private:
    int size;
    int getHash(std::string);

};