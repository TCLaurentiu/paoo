#include <iostream>
#include "string.hpp"

using std::cout;

int main(){
  char name[] = "Claudiu", name2[] = "Andrei", name3[] = "Miruna";
  String s_name = String(name);
  String s_name2 = String(s_name); 
  String s_name3 = String(name2);
  
  String s_name4 = std::move(s_name3);

  s_name4.append(name3);
  s_name4.append(s_name);

}