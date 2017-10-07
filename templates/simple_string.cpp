#include <gtest/gtest.h>
#include <vector>

template <typename Char>
struct CustomString {};

TEST(CustomString, emptyString) { CustomString<char> str; }
