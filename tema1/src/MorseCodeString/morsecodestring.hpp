#pragma once
#include "string.hpp"

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
      void setString(const char* c_string) override;
      void append(const char* c_string) override;
      void append(const char character) override;
      void append(const IString& other) override;

  };
}