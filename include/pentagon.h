#ifndef PENTAGON_H
#define PENTAGON_H

#pragma once
#include "figure.h"
#include <cmath>

template <Scalar T>
class Pentagon : public Figure<T> {

private:
    std::unique_ptr<Point<T>[]> points;

public:
    Pentagon() : points(std::make_unique<Point<T>[]>(5)) {}


    double Area() const override {
        double area = 0;
        for (int i = 0; i < 5; ++i)
            area += points[i].getX() * points[(i + 1) % 5].getY() -
                    points[(i + 1) % 5].getX() * points[i].getY();
        return std::abs(area) / 2.0;
    }

    Point<T> Center() const override {
        T cx = 0, cy = 0;
        for (int i = 0; i < 5; ++i) {
            cx += points[i].getX();
            cy += points[i].getY();
        }
        return Point<T>(cx / 5, cy / 5);
    }

    void Print(std::ostream& os) const override {
        os << "Пятиугольник: ";
        for (int i = 0; i < 5; ++i)
            os << points[i] << " ";
        os << "Площадь = " << Area()
                  << ", Центр = " << Center() << std::endl;
    }

    void Read(std::istream& is) override {
        for (int i = 0; i < 5; ++i) {
            is >> points[i];
        }
    }
};

#endif