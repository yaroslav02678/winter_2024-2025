#include "../../include/my_string/my_string.h"

MyString::MyString() : length(0) {}

MyString::MyString(const char* str) {
    length = 0;
    for (size_t i = 0; str[i] != '\0'; i++) {
        this->str.push_back(str[i]);
        length++;
    }    
}

MyString::MyString(const MyString& other) {
    length = 0;
    for (size_t i = 0; i < other.size(); i++) {
        this->str.push_back(other[i]);
        length++;
    }
}

MyString::~MyString() {
    clear();
}

const char& MyString::operator[](size_t index) const {
    return str[index];
}

char& MyString::operator[](size_t index) {
    return str[index];
}

size_t MyString::size() const {
    return length;
}

void MyString::clear() {
    str.clear();
    length = 0;
}

ostream& operator<<(ostream& os, const MyString& str) {
    for (size_t i = 0; i < str.size(); i++) {
        os << str[i];
    }
    return os;
}

MyString& MyString::operator=(const MyString& other) {
    clear();
    for (size_t i = 0; i < other.size(); i++) {
        this->str.push_back(other[i]);
        length++;
    }
    
    return *this;
}

MyString MyString::operator+(const MyString& other) {
    MyString new_str;
    new_str.str.reserve(size() + other.size());
    for (size_t i = 0; i < size(); i++) {
        new_str.str.push_back(str[i]);
    }
    for (size_t i = 0; i < other.size(); i++) {
        new_str.str.push_back(other[i]);
    }
    new_str.length = new_str.str.size(); 
    return new_str;
}

bool MyString::operator==(const MyString& other) const {
    if (size() != other.size()) {
        return false;
    }
    for (size_t i = 0; i < size(); i++) {
        if (str[i] != other[i]) {
            return false;
        }
    }
    return true;
}

bool MyString::operator!=(const MyString& other) {
    return !(*this == other);
}
