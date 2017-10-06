#include <gtest/gtest.h>
#include <array>
#include <sstream>

template <typename T, std::size_t N>
struct CircularBuffer {
    CircularBuffer() = default;

    CircularBuffer(const std::initializer_list<T>& list) {
        if (list.size() > N) {
            throw std::range_error("Range is not correct");
        }
        std::copy(std::begin(list), std::end(list), std::begin(_data));
    }

    const T& operator[](std::size_t index) const { return _data[index]; }

    void push(const T& t) {
        _data[currentIndex++] = t;
        if (currentIndex >= N) currentIndex = 0;
    }

   private:
    std::array<T, N> _data;
    std::size_t currentIndex{0};
};

template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const CircularBuffer<T, N>& buffer) {
    for (int i = 0; i < N; ++i) os << buffer[i];
    return os;
}

TEST(CircularBuffer, empty_buffer_is_zerod) {
    CircularBuffer<std::string, 10> buffer;
    EXPECT_EQ(buffer[0].size(), 0);
}

TEST(CircularBuffer, initialized_by_list) {
    CircularBuffer<std::string, 10> buffer{{"one", "two", "three"}};
    EXPECT_EQ(buffer[0], "one");
}

TEST(CircularBuffer, stream_operator) {
    using namespace std::string_literals;
    CircularBuffer<std::string, 2> buffer{{"one"s, "two"s}};
    std::stringstream ss; 
    ss << buffer;
    EXPECT_EQ(ss.str(), "onetwo");
}

TEST(CircularBuffer, initialized_too_big) {
    auto fn = []() {
        CircularBuffer<std::string, 2> buffer{{"one", "two", "three"}};
    };
    EXPECT_ANY_THROW(fn());
}

TEST(CircularBuffer, small_buffer) {
    CircularBuffer<std::string, 2> buffer;
    buffer.push("asd");
    buffer.push("asd");
    buffer.push("dd");
    buffer.push("bb");
    EXPECT_EQ(buffer[0], "dd");
    EXPECT_EQ(buffer[1], "bb");
}
