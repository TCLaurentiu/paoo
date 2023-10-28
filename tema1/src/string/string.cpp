#include "string.hpp"
#include <string.h>
#include <iostream>

using std::cout;

String::String(char *c_string){

  cout << c_string << " constructor called \n";

  this->size = strlen(c_string);
  this->capacity = this->size;
  this->c_string = new char[this->size + 1];
  strcpy(this->c_string, c_string);
}

String::~String(){

  cout << c_string << " destructor called \n";

  delete[] this->c_string;
}