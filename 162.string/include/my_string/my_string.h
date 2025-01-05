#ifndef MY_STRING_H
#define MY_STRING_H

#include "../../lib/libstdc++/include.cpp"

class MyString{
    vector<char> str;
    size_t length;
public:
    MyString();
    MyString(const char* new_line);
    MyString(const MyString& other);
    ~MyString();

    const char& operator[](size_t index) const; 
    char& operator[](size_t index);

    size_t size() const;
    void clear();
    
    friend ostream& operator<<(ostream& os, const MyString& str);

    MyString& operator=(const MyString& other);
    MyString operator+(const MyString& other);

    bool operator==(const MyString& other);
    bool operator!=(const MyString& other);

};

#endif // MY_STRING_H
