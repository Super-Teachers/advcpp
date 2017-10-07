#include <gtest/gtest.h>
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

namespace {
std::uint32_t gNewCount{0};
}

void* operator new(std::size_t sz) {
    gNewCount++;
    return std::malloc(sz);
}
void operator delete(void* ptr) noexcept {
    std::free(ptr);
}

template <std::size_t N, typename T, bool use_heap>
struct Array {
    Array() {
        if (use_heap) {
            _vector.reserve(N);
        }
    }

    T& operator[](std::size_t index) {
        if (use_heap) {
            return _vector[index];
        } else {
            return _array[index];
        }
    }

    const T& operator[](std::size_t index) const {
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
            return std::min_element(_array, _array + N);
        }
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
    EXPECT_NE(gNewCount, 0);

    // uninitialized
    EXPECT_EQ(heap[0], 0);

    heap[5] = 10;
    EXPECT_EQ(heap[5], 10);
}
