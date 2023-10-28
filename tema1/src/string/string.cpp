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

String::String(const String& other){

  cout << other.c_string << " copy constructor called \n";

  this->size = other.size;
  this->capacity = other.capacity;
  this->c_string = new char[this->size + 1];
  strcpy(this->c_string, other.c_string);
}

String::String(String&& other){

  cout << other.c_string << " move constructor called \n";

  this->size = other.size;
  this->capacity = other.capacity;
  this->c_string = other.c_string;
  
  other.c_string = nullptr;
}

void String::resize(int new_size){
  char *new_c_string = new char[new_size + 1];
  strcpy(new_c_string, this->c_string);
  delete[] c_string;
  this->c_string = new_c_string;
}

char *String::getString(){
  return this->c_string;
}

void String::setString(const char *c_string){
  int len = strlen(c_string);
  if(len > this->capacity){
    this->resize(len);
  }
  strcpy(this->c_string, c_string);
}

void String::append(const char *c_string){
  int len = strlen(c_string);
  if(this->size + len > this->capacity){
    this->resize(this->size + len);
  }
  strcat(this->c_string, c_string);
}

void String::append(const String other){
  this->append(other.c_string);
}