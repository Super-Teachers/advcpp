#include <algorithm>
#include <array>
#include <vector>

template <std::size_t N, typename T, bool use_heap>
struct Array {
    T& operator[](std::size_t index) { return _vector[index]; }
    const T& operator[](std::size_t index) const { return _vector[index]; }

    T min() const {
        return std::min_element(std::begin(_vector), std::end(_vector));
    }

   private:
    std::vector<T> _vector;
};

template <std::size_t N, typename T>
struct Array<N, T, false> {
    T& operator[](std::size_t index) { return _array[index]; }
    const T& operator[](std::size_t index) const { return _array[index]; }

    template <std::size_t Index>
    T& get() {
        static_assert(Index <= N, "Index cannot be smaller that N");
    }

   private:
    std::array<T, N> _array;
};

int main(int, char* []) {
    Array<10, int, false> arr;

    return 0;
}
