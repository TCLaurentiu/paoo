#pragma once
#include "IString.hpp"

namespace MyString
{

  class String : public IString
  {
  private:
    int size;
    int capacity;
    char *c_string;
    void resize(int new_size);

  public:
    String(const char *c_string);
    ~String();
    String(const String &other);
    String(String &&other);

    void setString(const char *c_string);
    char *to_c_string() const;

    void append(const char character);
    void append(const char *c_string);
    void append(const IString &other);
  };
}