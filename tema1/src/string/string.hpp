#pragma once
#include "IString.hpp"

namespace MyString
{

  class String : public IString
  {
  protected:
    int size;
    int capacity;
    char *c_string;
    void resize(int new_size);

  public:
    String();
    String(const char *c_string);
    virtual ~String();
    String(const String &other);
    String(String &&other);
    String& operator=(const String& other);
    String& operator=(String&& other);
    bool operator==(const String& other) const;

    virtual void setString(const char *c_string);
    char *to_c_string() const;

    virtual void append(const char character);
    virtual void append(const char *c_string);
    virtual void append(const IString &other);
  };
}