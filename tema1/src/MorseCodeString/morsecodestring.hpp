#pragma once
#include "string.hpp"

#define MaxLetterLength 4
#define DigitLength 5
#define SpecialLength 6
#define SpecialCount 3
#define DigitCount 10
#define LetterCount 26
#define MaxMorseCharacterLength 6

namespace MyString
{
  class MorseCodeString : public String
  {
    public:
      MorseCodeString(const char *morse_string);
      MorseCodeString(const MorseCodeString& other);
      MorseCodeString(MorseCodeString&& other);

      MorseCodeString& operator=(const MorseCodeString& other);
      MorseCodeString& operator=(MorseCodeString&& other);
      void setString(const char *c_string) override;
      void append(const char* c_string) override;
      void append(const char character) override;
      void append(const IString& other) override;
      String ToAlphaNumerical();

    private:

      /* 
      checks if a string is valid morse code
      that is, it is a space delimited string of . and -
      where every group of . and - matches one of the
      morse codes defined in morse_letters/digits/specials
      returns the corresponding alpha-numerical String
      or an empty string if the input is invalid
      */
      String MorseCodeToAlpha(const char *);

      /*
      converts a morse code character to its alpha numerical counterpart
      returns -1 if the character is invalid
      */
      char MorseCodeCharacterToAlpha(const char *);

      static const char* morse_letters[LetterCount];
      static const char* morse_digits[DigitCount];
      
      static const char alpha_specials[SpecialCount];
      static const char* morse_specials[SpecialCount];

      String AlphaNumerical;

  };
}