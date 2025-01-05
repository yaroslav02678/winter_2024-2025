#include "../../include/my_string.h"

MyString::MyString() {}

MyString::MyString(const char* str) {
    length = 0;
    for (size_t i = 0; str[i] != '\0'; i++) {
        this->str.push_back(str[i]);
        length++;
    }    
}

MyString::MyString(const MyString& other) {
    for (size_t i = 0; i < other.size(); i++) {
        this->str.push_back(other[i]);
    }
}

MyString::~MyString() {
    clear();
}

char MyString::operator[](size_t index) const {
    return str[index];
}

char MyString::operator[](size_t index) {
    return str[index];
}

size_t MyString::size() const {
    return length;
}

void MyString::clear() {

}

ostream& operator<<(ostream& os, const MyString& str) {

}

MyString& MyString::operator=(const MyString& other) {

}

MyString MyString::operator+(const MyString& other) {

}

bool MyString::operator==(const MyString& other) {

}

bool MyString::operator!=(const MyString& other) {

}