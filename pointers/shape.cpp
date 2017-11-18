#include <gtest/gtest.h>
#include <iostream>
#include <random>

namespace {
const int min = 0;
const int max = 100;
}  // namespace

int randomValue() {
    std::random_device rd;
    std::default_random_engine engine{rd()};
    std::uniform_int_distribution<int> dist{min, max};

    return dist(engine);
}

struct Shape {
    virtual ~Shape() = default;
    virtual double area() const noexcept = 0;
};

struct Rect : public Shape {
    double area() const noexcept override { return _a * _b; }
    Rect(int a, int b) : _a(a), _b(b) {}

   private:
    int _a, _b;
};
struct Circle : public Shape {
    double area() const noexcept override { return M_PI * _radius; }
    Circle(double radius) : _radius(radius) {}

   private:
    double _radius;
};

Shape* create(const std::string& shape) {
    if (shape == "rect") return new Rect(randomValue(), randomValue());
    if (shape == "circle") return new Circle(randomValue());

    return nullptr;
}

double area(Shape* p) { return p->area(); }

TEST(Shape, Rect) {
    auto sh = create("rect");

    EXPECT_GE(sh->area(), min * min);
    EXPECT_LE(sh->area(), max * max);

    delete sh;
}
TEST(Shape, Circle) {
    auto sh = create("circle");

    EXPECT_GE(sh->area(), min * M_PI);
    EXPECT_LE(area(sh), max * M_PI);

    delete sh;
}
