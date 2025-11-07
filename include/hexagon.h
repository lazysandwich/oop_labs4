#ifndef HEXAGON_H
#define HEXAGON_H
#include "figure.h"
#include <cmath>

template <Scalar T>
class Hexagon : public Figure<T> {

private:
    std::unique_ptr<Point<T>[]> points;

public:
    Hexagon() : points(std::make_unique<Point<T>[]>(6)) {}

    double Area() const override {
        double area = 0;
        for (int i = 0; i < 6; ++i)
            area += points[i].getX() * points[(i + 1) % 6].getY() -
                    points[(i + 1) % 6].getX() * points[i].getY();
        return std::abs(area) / 2.0;
    }

    Point<T> Center() const override {
        T cx = 0, cy = 0;
        for (int i = 0; i < 6; ++i) {
            cx += points[i].getX();
            cy += points[i].getY();
        }
        return Point<T>(cx / 6, cy / 6);
    }

    void Print(std::ostream& os) const override {
        os << "Шестиугольник: ";
        for (int i = 0; i < 6; ++i)
            os << points[i] << " ";
        os << "Площадь = " << Area()
                  << ", Центр = " << Center() << std::endl;
    }

    void Read(std::istream& is) override {
        for (int i = 0; i < 6; ++i) {
            is >> points[i];
        }
    }
};

#endif