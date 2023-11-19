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
