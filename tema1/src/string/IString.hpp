namespace String {
  class IString{
    public:
      virtual void resize(int new_size) = 0;
      virtual char* to_c_string() const = 0;
      virtual void setString(const char *string) = 0;
      virtual void append(const char character) = 0;
      virtual void append(const char *string) = 0;
      virtual void append(const IString& string);
  };
}