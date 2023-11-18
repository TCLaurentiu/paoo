namespace MyString {
  class IString{
    public:
      virtual char* to_c_string() const = 0;
      virtual void setString(const char *string) = 0;
      virtual void append(const char character) = 0;
      virtual void append(const char *string) = 0;
      virtual void append(const IString& string) = 0;
    private:
      virtual void resize(int new_size) = 0;
  };
}