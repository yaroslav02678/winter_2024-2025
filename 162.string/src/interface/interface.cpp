#include "../../include/interface/interface.h"

void TextInterface::run() {
    bool exit = false;
    MyString str;

    while (!exit) {
        printMenu();
        int choice;
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                str = inputString();
                break;
            case 2:
                displayString(str);
                break;
            case 3:
                addStrings(str);
                break;
            case 4:
                compareStrings(str);
                break;
            case 5:
                clearString(str);
                break;
            case 6:
                exit = true;
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

void TextInterface::printMenu() {
    cout << "\nMenu:\n";
    cout << "1. Enter a string\n";
    cout << "2. Display the string\n";
    cout << "3. Add a string\n";
    cout << "4. Compare two strings\n";
    cout << "5. Clear the string\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

MyString TextInterface::inputString() {
    cout << "Enter a string: ";
    char* inputBuffer = new char[1000]; 
    cin.getline(inputBuffer, 1000);

    MyString newStr(inputBuffer);

    delete[] inputBuffer;
    return newStr;
}

void TextInterface::displayString(const MyString& str) {
    cout << "Current string: " << str << "\n";
}

void TextInterface::addStrings(MyString& str) {
    MyString anotherStr = inputString();
    str = str + anotherStr;
    cout << "Strings added. New string: " << str << "\n";
}

void TextInterface::compareStrings(const MyString& str) {
    MyString anotherStr = inputString();
    if (str == anotherStr) {
        cout << "Strings are equal.\n";
    } 
    else {
        cout << "Strings are not equal.\n";
    }
}

void TextInterface::clearString(MyString& str) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

