class String{
  private:
    int size;
    int capacity;
    char *c_string;
    void resize(int new_size);
  public:
    String(char *c_string);
    ~String();
    String(const String& other);
    String(String&& other);

    void setString(const char *c_string);
    char *getString();

    void append(const char *c_string);
    void append(const String other);

};