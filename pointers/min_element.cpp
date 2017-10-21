#include <gtest/gtest.h>

namespace one {
template <typename T>
T minElement(T* array, std::size_t size) {
}
template<typename T>
T minElement(T array, std::size_t size) {
}
}  // namespace one

namespace two {
template <typename T>
T minElement(T array[], std::size_t size) {
}
}  // namespace two

TEST(MinElement, one) {
    //std::array<double, 5> d{0, 1, 2, 3, 4};
    //EXPECT_EQ(one::minElement(d.data(), d.size()), 0);
}
TEST(MinElement, two) {
    //float array[] = {0, 1, 2, 3, 4, 5, 6};
    //EXPECT_EQ(two::minElement(array, 6), 0);
}
