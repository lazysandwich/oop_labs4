#ifndef Figure_H
#define Figure_H

#include "point.h"
#include <memory>
#include <vector>

template <Scalar T>
class Figure {
    
public:
    virtual ~Figure() = default;

    virtual double Area() const = 0;
    virtual Point<T> Center() const = 0;

    virtual operator double() const { return Area(); }

    virtual bool operator==(const Figure<T>& other) const {
        return std::abs(Area() - other.Area()) < 1e-9;
    }

private:
    virtual void Print(std::ostream& os) const = 0;
    virtual void Read(std::istream& is) = 0;

friend std::ostream& operator<<(std::ostream& os, const Figure& a) {
        a.Print(os);
        return os;
    }
friend std::istream& operator>>(std::istream& is, Figure& a) {
        a.Read(is);
        return is;
    }

};

#endif