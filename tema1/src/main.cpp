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

  cout << "\n ---- \n\n";
  MorseCodeString mcs1("-.-. .-.. .- ..- -.. .. ..-");
  MorseCodeString mcs2(MorseCodeString(".- -. .-"));
  MorseCodeString mcs3(mcs2);
  mcs3 = MorseCodeString("-.-. .-.. .- ..- -.. .. ..-");
  mcs3 = mcs2;

  mcs3.append("-. .-");
  mcs3.append(mcs2);

  String s4 = mcs1.ToAlphaNumerical();
  String s5 = mcs3.ToAlphaNumerical();
  cout << "\n";
  cout << mcs1.to_c_string() << " = " << s4.to_c_string() << "\n";
  cout << mcs3.to_c_string() << " = " << s5.to_c_string() << "\n";
  cout << "\n";

  cout << "\n ---- \n\n";

  String *base;
  base = &mcs1;
  base->append("..-");
  cout << base->to_c_string() << "\n";

  cout << "\n ---- \n\n";

  return 0;

}