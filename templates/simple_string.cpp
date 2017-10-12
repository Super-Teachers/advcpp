#include <algorithm>
#include <gtest/gtest.h>
#include <vector>

template <typename Char> struct CustomString {

  template <typename T>
  friend bool operator==(const CustomString<T> &custom, const std::string &str);

  CustomString() = default;
  CustomString(const Char *ptr) {
    std::copy(ptr, ptr + std::strlen(ptr), std::back_inserter(_data));
  }

  CustomString(const std::basic_string<Char> &str) {
    std::copy(std::begin(str), std::end(str), std::back_inserter(_data));
  }

  CustomString(const CustomString<Char>& rhs)
  {
      std::copy(std::begin(rhs._data), std::end(rhs._data), std::back_inserter(_data));
  }

  CustomString& operator += (const CustomString<Char>& other)
  {
      std::copy(std::begin(other._data), std::end(other._data), std::back_inserter(_data));
      return *this;
  }

private:
  std::vector<Char> _data;
};

template <typename T>
bool operator==(const CustomString<T> &custom, const std::string &str) {
  std::string tmp;
  std::copy(std::begin(custom._data), std::end(custom._data),
            std::back_inserter(tmp));

  return tmp == str;
}

TEST(CustomString, emptyString) {
  CustomString<char> str;
  EXPECT_EQ(str, "");
}

TEST(CustomString, init_from_const_char) {
  CustomString<char> str{"this is a char"};
  EXPECT_EQ(str, "this is a char");
}

TEST(CustomString, init_from_basic_string) {
  CustomString<char> str{"this is a char"};
  EXPECT_EQ(str, "this is a char");
}

TEST(CustomString, plus_assign_operator) {
  CustomString<char> str{"t"};
  str += CustomString<char> { "i"};
  EXPECT_EQ(str, "ti");
}
TEST(CustomString, copyctor) {
  CustomString<char> str{"this is a str"};
  auto k = str;
  EXPECT_EQ(k, "this is a str");
}
