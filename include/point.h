#ifndef POINTS_H
#define POINTS_H
#include <iostream>
#include <concepts>
#include <memory>

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

template <Scalar T>
class Point {

public:
    T x{}, y{};

    Point() = default;
    Point(T x, T y) : x(x), y(y) {}

    friend std::istream& operator>>(std::istream& in, Point& p) {
        in >> p.x >> p.y;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Point& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

#endif