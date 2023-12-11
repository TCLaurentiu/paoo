#include "stringinthashmap.hpp"

#define p 31
#define m = 1e9 + 9

StringIntHashMap::StringIntHashMap(int size) {
  this -> size = size;
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