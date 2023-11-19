#include "morsecodestring.hpp"
#include "string.hpp"

#include <iostream>
#include <string.h>

using MyString::MorseCodeString;
using MyString::String;
using std::move;

const char* MorseCodeString::morse_letters[26] = {
  ".-", "-...", "-.-.", "-..", // A, B, C, D
  ".", "..-.", "--.", "....", // E, F, G, H
  "..", ".---", "-.-", ".-..", // I, J, K, L
  "--", "-.", "---", ".--.", // M, N, O, P
  "--.-", ".-.", "...", "-",// Q, R, S, T
  "..-", "...-", ".--", "-..-", // U, V, W, X
  "-.--", "--.." // Y, Z
};
const char* MorseCodeString::morse_digits[10] = {
  "-----",
  ".----",
  "..---",
  "...--",
  "....-",
  ".....",
  "-....",
  "--...",
  "---..",
  "----.",
};
      
const char MorseCodeString::alpha_specials[3] = {'.', ',', '?'};
const char* MorseCodeString::morse_specials[3] = {
  ".-.-.-",
  "--..--",
  "..--..",
};

MorseCodeString::MorseCodeString(const char *string) : String(string){
  this->setString(string);
}

MorseCodeString::MorseCodeString(const MorseCodeString& other) : String(other){
  this->AlphaNumerical = other.AlphaNumerical;
}

MorseCodeString::MorseCodeString(MorseCodeString&& other) : String(std::move(other)){
  this->AlphaNumerical = std::move(other.AlphaNumerical);
}

MorseCodeString& MorseCodeString::operator=(const MorseCodeString& other){
  String::operator=(other);
  this->AlphaNumerical = other.AlphaNumerical;
  return *this;
}

MorseCodeString& MorseCodeString::operator=(MorseCodeString&& other){
  String::operator=(std::move(other));
  this->AlphaNumerical = std::move(other.AlphaNumerical);
  return *this;
}

String MorseCodeString::MorseCodeToAlpha(const char* string){

  String alpha_string;
  
  char converted_character;

  size_t len = strlen(string);

  char *aux = new char[MaxMorseCharacterLength + 1];
  size_t current_character_len = 0;

  for(size_t i = 0;i<len;i++){
    if(string[i] == ' '){
      aux[current_character_len] = '\0';
      converted_character = MorseCodeString::MorseCodeCharacterToAlpha(aux);
      if(converted_character == -1){
        return String();
      }

      alpha_string.append(converted_character);
      current_character_len = 0;
    } else {
      if (current_character_len + 1 > MaxMorseCharacterLength){
        return String();
      }
      aux[current_character_len++] = string[i];
    }
  }

  aux[current_character_len] = '\0';
  converted_character = MorseCodeString::MorseCodeCharacterToAlpha(aux);
  if (converted_character == -1){
    return String();
  }
  alpha_string.append(converted_character);
  
  delete[] aux;

  return alpha_string;

}

char MorseCodeString::MorseCodeCharacterToAlpha(const char* string){
  int len = strlen(string);

  if(len == SpecialLength){
    for(size_t i = 0;i < SpecialCount;i++){
      if(strcmp(string, MorseCodeString::morse_specials[i]) == 0){
        return MorseCodeString::alpha_specials[i];
      }
    }
  }

  if(len == DigitLength){
    for(size_t i = 0;i<DigitCount;i++){
      if(strcmp(string, MorseCodeString::morse_digits[i]) == 0){
        return '0' + i;
      }
    }
  }

  for(size_t i = 0;i<LetterCount;i++){
    if(strcmp(string, MorseCodeString::morse_letters[i]) == 0){
      return 'A' + i;
    }
  }

  return -1;

}

void MorseCodeString::setString(const char *c_string){

  this->AlphaNumerical = MorseCodeString::MorseCodeToAlpha(c_string);
  if(this->AlphaNumerical == String()){
    throw std::invalid_argument("MorseCodeString constructor expects a valid Morse Code String");
  }
}