#include <iostream>
#include "string.hpp"

using std::cout;
using MyString::String;

String ret(String a){
  return a;
}

int main(){
  String s_name("Claudiu");
  String s_name2(s_name);

}