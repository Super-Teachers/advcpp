#include <algorithm>
#include <array>
#include <vector>

template <std::size_t N, typename T, bool use_heap>
struct Array {
    T& operator[](std::size_t index) {
        return _data[index];
    }
    const T& operator[](std::size_t index) const { return _data[index]; }

    auto min() const {
        if constexpr (use_heap) {
            return std::min_element(std::begin(_data), std::end(_data));
        } else {
            return std::min_element(_data, _data + N);
        }
    }

   private:
    typename std::conditional<use_heap, std::vector<T>, std::array<T, N>>::type
        _data;
};

int main(int, char* []) {
    Array<10, int, false> arr;

    arr[9] = 0;

    return 0;
}
