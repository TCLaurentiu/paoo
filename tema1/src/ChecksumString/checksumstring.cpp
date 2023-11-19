#include "checksumstring.hpp"
#include "string.hpp"

#include <iostream>
#include <string.h>

using MyString::ChecksumString;
using MyString::String;
using std::move;

char ChecksumString::getChecksum(){
  char checksum = 0;
  if (this->c_string == NULL){
    return checksum;
  }

  size_t len = strlen(this->c_string);
  for(size_t i = 0;i<len;i++){
    checksum ^= this->c_string[i];
  }
  return checksum;
}