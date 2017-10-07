#include <gtest/gtest.h>
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

template <std::size_t N, typename T, bool use_heap>
struct Array {
    Array() {
    }

    T& operator[](std::size_t index) {
    }

    const T& operator[](std::size_t index) const {
    }

    T min() const {
    }

   private:
    std::vector<T> _vector;
    std::array<T, N> _array;
};

TEST(Array, stack_simple) {
    Array<10, int, false> stack;

    // uninitialized
    EXPECT_NE(stack[0], 0);

    stack[5] = 10;
    EXPECT_EQ(stack[5], 10);
}

TEST(Array, heap_simple) {
    Array<10, int, true> heap;

    // uninitialized
    EXPECT_EQ(heap[0], 0);

    heap[5] = 10;
    EXPECT_EQ(heap[5], 10);
}
