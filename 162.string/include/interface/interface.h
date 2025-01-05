#ifndef TEXT_INTERFACE_H
#define TEXT_INTERFACE_H

#include "../my_string/my_string.h" 

class TextInterface {
    void printMenu();
    void displayString(const MyString& str);
    MyString inputString();
    void addStrings(MyString& str);
    void compareStrings(const MyString& str);
    void clearString(MyString& str);

public:
    void run();

};

#endif // TEXT_INTERFACE_H
