#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& container) {
    for (const auto& v : container) os << v;
    return os;
}

TEST(TemplatedOperator, emptyVector) {
    std::vector<std::string> empty;
    std::stringstream ss;

    ss << empty;

    EXPECT_EQ(ss.str(), "");
}

TEST(TemplatedOperator, stringVector) {
    std::vector<std::string> data{{"a", "b", "c"}};
    std::stringstream ss;

    ss << data;

    EXPECT_EQ(ss.str(), "abc");
}
