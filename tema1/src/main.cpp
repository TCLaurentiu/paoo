#include <iostream>
#include "string.hpp"
#include "morsecodestring.hpp"

using std::cout;
using MyString::String;
using MyString::MorseCodeString;

int main(){
  String s1("Claudiu");
  String s2(String("Andrei"));
  String s3(s2);
  s3 = String("Andreea");
  s3 = s2;
  s3.append("Iuliana");
  s3.append(' ');
  s3.append(s1);

  cout << "\n";
  cout << s1.to_c_string() << " " << s2.to_c_string() << " " << s3.to_c_string() << "\n";
  cout << "\n";

}