#include "string.hpp"
#include <string.h>
#include <iostream>

using std::cout;

using MyString::String;

String::String(const char *c_string){

  cout << c_string << " constructor called \n";
  this->size = strlen(c_string) + 1;
  this->capacity = this->size;
  this->c_string = new char[this->capacity];
  strcpy(this->c_string, c_string);
}

String::String(){
  cout << "default constructor called \n";

  this->size = 0;
  this->capacity = 0;
  this->c_string = NULL;

}

String::~String(){

  if(this->c_string == nullptr){
    cout << "Destructor of moved object called \n";
    return;
  }

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
  other.capacity = 0;
  other.size = 0;

}

String& String::operator=(const String& other){
  
  cout << other.c_string << " copy assignment called \n";

  if (this != &other){
    this->size = other.size;
    this->capacity = other.capacity;
    delete[] this->c_string;
    this->c_string = new char[this->size + 1];
    strcpy(this->c_string, other.c_string);
  }

  return *this;

}

String& String::operator=(String&& other){
  
  cout << other.c_string << " move assignment called \n";

  if (this != &other){
    this->size = other.size;
    this->capacity = other.capacity;
    delete[] this->c_string;
    this->c_string = other.c_string;

    other.size = 0;
    other.capacity = 0;
    other.c_string = nullptr;

  }

  return *this;

}

void String::resize(int new_capacity){
  if(this->c_string == NULL){
    this->c_string = new char[new_capacity];
    return;
  }
  char *new_c_string = new char[new_capacity];
  strcpy(new_c_string, this->c_string);
  this->capacity = new_capacity;
  delete[] c_string;
  this->c_string = new_c_string;
}

char *String::to_c_string() const{
  return this->c_string;
}

void String::setString(const char *c_string){
  int len = strlen(c_string);
  if(len + 1> this->capacity){
    this->resize(len + 1);
  }
  strcpy(this->c_string, c_string);
  this->size = len + 1;
}

void String::append(const char *c_string){
  int len = strlen(c_string);
  if(this->size + len > this->capacity){
    this->resize(this->size + len);
  }
  strcat(this->c_string, c_string);
  this->size += len;
}

void String::append(const char character){

  if(this->c_string == NULL){
    this->resize(2);
    this->size = 2;
    this->c_string[0] = character;
    this->c_string[1] = '\0';
    return;
  }

  if(this->size + 1 > this -> capacity){
    this->resize(this->size + 1);
  }

  this->c_string[this->size - 1] = character;
  this->c_string[this->size] = '\0';
  this->size ++;
}

void String::append(const IString& other){
  this->append(((String&)other).c_string);
}