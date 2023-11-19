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
      void append(const char* c_string) override;
      void append(const char character) override;
      void append(const IString& other) override;

    private:


      static const char* morse_letters[LetterCount];
      static const char* morse_digits[DigitCount];
      
      static const char alpha_specials[SpecialCount];
      static const char* morse_specials[SpecialCount];

  };
}