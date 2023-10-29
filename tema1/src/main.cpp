#include <iostream>
#include "string.hpp"

using std::cout;

String ret(String a){
  return a;
}

int main(){
  String s_name("Claudiu");
  String s_name2(s_name); 
  String s_name3("Miruna");
  
  String s_name4(std::move(s_name3));

  s_name4.append("Andrei");
  s_name4.append(s_name);

  String s_name5(ret(String("Eustachio")));

}