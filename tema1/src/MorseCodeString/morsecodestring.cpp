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