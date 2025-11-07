#ifndef RHOMBUS_H
#define RHOMBUS_H

#pragma once
#include "figure.h"
#include <cmath>

template <Scalar T>
class Rhombus : public Figure<T> {

private:
    std::unique_ptr<Point<T>[]> points;

public:
    Rhombus() : points(std::make_unique<Point<T>[]>(4)) {}

    double Area() const override {
        double area = 0;
        for (int i = 0; i < 4; ++i)
            area += points[i].getX() * points[(i + 1) % 4].getY() -
                    points[(i + 1) % 4].getX() * points[i].getY();
        return std::abs(area) / 2.0;
    }

    Point<T> Center() const override {
        T cx = 0, cy = 0;
        for (int i = 0; i < 4; ++i) {
            cx += points[i].getX();
            cy += points[i].getY();
        }
        return Point<T>(cx / 4, cy / 4);
    }

    void Print(std::ostream& os) const override {
        os << "Ромб: ";
        for (int i = 0; i < 4; ++i)
            os << points[i] << " ";
        os << "Площадь = " << Area()
                  << ", Центр = " << Center() << std::endl;
    }

    void Read(std::istream& is) override {
        for (int i = 0; i < 4; ++i) {
            is >> points[i];
        }
    }
};

#endif