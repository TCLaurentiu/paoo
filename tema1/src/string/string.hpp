class String{
  private:
    int size;
    int capacity;
    char *c_string;
  public:
    String(char *c_string);
    ~String();
    String(const String& other);
    String(String&& other);

    void setString(const char *c_string);
    char *getString();

    void resize(int new_size);
    void append(const char *c_string);
    void append(const String other);

};