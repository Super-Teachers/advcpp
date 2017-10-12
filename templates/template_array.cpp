#include <algorithm>
#include <array>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

template <std::size_t N, typename T, bool use_heap> struct Array {
  Array() {
    if (use_heap) {
      _vector.reserve(N);
    }
  }

  Array(const std::initializer_list<T> &init) {
    if (use_heap) {
      std::copy(std::begin(init), std::end(init), std::back_inserter(_vector));
    } else {
      if (init.size() != N) {
        throw std::runtime_error("");
      }
      std::copy_n(std::begin(init), N, _array.begin());
    }
  }

  T &operator[](std::size_t index) {
    if (use_heap)
      return _vector[index];
    else
      return _array[index];
  }

  const T &operator[](std::size_t index) const {
    if (use_heap) {
      return _vector[index];
    } else {
      return _array[index];
    }
  }

  T min() const {
    if (use_heap) {
      return std::min_element(std::begin(_vector), std::end(_vector));
    } else {
      return std::min_element(std::begin(_array), std::end(_array));
    }
  }

  T max() const {
    if (use_heap) {
      return std::max_element(std::begin(_vector), std::end(_vector));
    } else {
      return std::max_element(std::begin(_array), std::end(_array));
    }
  }

private:
  std::vector<T> _vector;
  std::array<T, N> _array;
};

TEST(Array, empty_array_is_zero_initialized) {
  Array<10, int, false> stack;
  EXPECT_EQ(stack[0], 0);

  Array<10, int, true> heap;
  EXPECT_EQ(heap[0], 0);
}

TEST(Array, stack_simple) {
  Array<10, int, false> stack;
  stack[5] = 10;
  EXPECT_EQ(stack[5], 10);
}

TEST(Array, heap_simple) {
  Array<10, int, true> heap;

  heap[5] = 10;
  EXPECT_EQ(heap[5], 10);
}

TEST(Array, array_stack_initialized) {
  Array<3, std::string, false> stack{"", "empty", "ttt"};
  EXPECT_TRUE(stack[0].empty());
  EXPECT_EQ(stack[2], "ttt");
}

template<typename T>
void foo(T t)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

TEST(Array, array_stack_initialized_incorrect) {
  auto fn = []() { Array<1, std::string, false> stack{"", "empty", "ttt"}; };

  EXPECT_ANY_THROW(fn());
  int a =10;
  int &b = a;
  foo(std::ref(b));
}
