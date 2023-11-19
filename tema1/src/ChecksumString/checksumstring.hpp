#pragma once
#include "string.hpp"

namespace MyString
{
  class ChecksumString : public String
  {
    using String::String;
    public:
      char getChecksum();
  };
}