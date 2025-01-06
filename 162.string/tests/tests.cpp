#include <gtest/gtest.h>
#include "../include/my_string/my_string.h"

// Тест конструктора за замовчуванням
TEST(MyStringTest, DefaultConstructor) {
    MyString str;
    EXPECT_EQ(str.size(), 0);
}

// Тест конструктора з `const char*`
TEST(MyStringTest, CharPointerConstructor) {
    MyString str("Hello");
    EXPECT_EQ(str.size(), 5);
    EXPECT_EQ(str[0], 'H');
    EXPECT_EQ(str[4], 'o');
}

// Тест конструктора копіювання
TEST(MyStringTest, CopyConstructor) {
    MyString original("Test");
    MyString copy(original);
    EXPECT_EQ(copy.size(), 4);
    EXPECT_TRUE(copy == original);
}

// Тест оператора `=` (присвоєння)
TEST(MyStringTest, AssignmentOperator) {
    MyString str1("Hello");
    MyString str2;
    str2 = str1;
    EXPECT_EQ(str2.size(), 5);
    EXPECT_TRUE(str2 == str1);
}

// Тест оператора `+` (додавання)
TEST(MyStringTest, AdditionOperator) {
    MyString str1("Hello");
    MyString str2("World");
    MyString result = str1 + str2;
    EXPECT_EQ(result.size(), 10);
    EXPECT_EQ(result[0], 'H');
    EXPECT_EQ(result[5], 'W');
    EXPECT_EQ(result[9], 'd');
}

// Тест оператора `==` (порівняння)
TEST(MyStringTest, EqualityOperator) {
    MyString str1("Test");
    MyString str2("Test");
    EXPECT_TRUE(str1 == str2);
}

// Тест оператора `!=` (нерівність)
TEST(MyStringTest, InequalityOperator) {
    MyString str1("Hello");
    MyString str2("World");
    EXPECT_TRUE(str1 != str2);
}

// Тест оператора `[]` для читання
TEST(MyStringTest, IndexOperatorConst) {
    const MyString str("Test");
    EXPECT_EQ(str[0], 'T');
    EXPECT_EQ(str[3], 't');
}

// Тест оператора `[]` для запису
TEST(MyStringTest, IndexOperatorNonConst) {
    MyString str("Test");
    str[0] = 'B';
    EXPECT_EQ(str[0], 'B');
}

// Тест методу `clear()`
TEST(MyStringTest, ClearMethod) {
    MyString str("ClearMe");
    str.clear();
    EXPECT_EQ(str.size(), 0);
    EXPECT_TRUE(str == MyString());
}

// Тест оператора `<<` для виводу
TEST(MyStringTest, StreamOperator) {
    MyString str("StreamTest");
    std::ostringstream oss;
    oss << str;
    EXPECT_EQ(oss.str(), "StreamTest");
}

// Тест деструктора (неявно)
TEST(MyStringTest, Destructor) {
    MyString* str = new MyString("Test");
    EXPECT_EQ(str->size(), 4);
    delete str;
    // Після delete перевірити неможливо, але перевіряємо, що деструктор не падає.
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
