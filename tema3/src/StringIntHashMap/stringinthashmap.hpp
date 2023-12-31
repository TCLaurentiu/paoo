#pragma once
#include <string>
#include <vector>
#include <utility>
#include <optional>
#include "linkedlist.hpp"

/*
a hashmap that has strings as keys and ints as values
keys corresponding to a bucket are stored in a linked list
insertion is done at the beginning of the list
on access elements are moved to the beginning of the list
*/
class StringIntHashMap{
  public:
    StringIntHashMap(int);
    void insert_reorder(std::pair<std::string, int>);
    bool exists(std::string key);
    std::optional<int> get(std::string key);

    int size;
    unsigned int getHash(std::string);
    
    std::vector<std::string> getKeys();

    std::optional<std::pair<std::string, int>> get_largest_in_bucket(int bucket_id);

    void print();
  
  private:
    std::vector<LinkedList> buckets;

};