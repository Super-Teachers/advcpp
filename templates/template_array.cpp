#include <algorithm>
#include <array>
#include <vector>

template <std::size_t N, typename T, bool use_heap>
struct Array {
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

int main(int, char* []) {
    Array<10, int, false> arr;
    return 0;
}
