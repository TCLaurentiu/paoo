#include "stringinthashmap.hpp"
#include <iostream>

#define p 31
#define m = 1e9 + 9

StringIntHashMap::StringIntHashMap(int size) {
  this -> size = size;
  this -> buckets = std::vector<LinkedList>(this->size, LinkedList());
}

std::optional<int> StringIntHashMap::get(std::string key) {
  unsigned int hashcode = this->getHash(key);
  return this->buckets[hashcode].get_second(key);
}

void StringIntHashMap::insert_reorder(std::pair<std::string, int> element){
  unsigned int hashcode = this->getHash(element.first);
  this->buckets[hashcode].remove(element.first);
  this->buckets[hashcode].insert_front(element);
}

/*
interprets every 4 bytes of the string as a number
adds them up and applies modulo the size of the hashmap
*/
unsigned int StringIntHashMap::getHash(std::string string){

  unsigned int sum = 0;
  // mul will always be equal to 256^(i mod 4)
  unsigned int mul = 1;
  for(int i = 0; i<string.length(); i++){
    if (i%4 == 0){
      mul = 1;
    } else {
      mul = mul * 256;
    }

    sum += string[i] * mul;

  }

  return sum % this -> size;

}

std::vector<std::string> StringIntHashMap::getKeys() {
  std::vector<std::string> v;
  for(int i =0;i<this->size;i++) {
    std::vector<std::string> bucket_v = this->buckets[i].first_component_to_vector();
    v.insert(v.end(), bucket_v.begin(), bucket_v.end());
  }
  return v;
}

std::optional<std::pair<std::string, int>> StringIntHashMap::get_largest_in_bucket(int bucket_id) {
  return this->buckets[bucket_id].get_largest();
}

void StringIntHashMap::print() {
  for (int i = 0;i<this->size;i++){
    std::cout << "Bucket " << i << ":\n";
    this->buckets[i].print();
  }
}