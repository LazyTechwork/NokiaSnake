
#include "Point2D.h"

namespace Common {
    Point2D Common::Point2D::operator+(Point2D p) const {
        return {static_cast<int16_t>(x + p.x), static_cast<int16_t>(y + p.y)};
    }

    bool Point2D::operator==(const Point2D &rhs) const {
        return x == rhs.x &&
               y == rhs.y;
    }

    bool Point2D::operator!=(const Point2D &rhs) const {
        return !(rhs == *this);
    }

    bool Point2D::operator<(const Point2D &rhs) const {
        if (x < rhs.x)
            return true;
        if (rhs.x < x)
            return false;
        return y < rhs.y;
    }

    bool Point2D::operator>(const Point2D &rhs) const {
        return rhs < *this;
    }

    bool Point2D::operator<=(const Point2D &rhs) const {
        return !(rhs < *this);
    }

    bool Point2D::operator>=(const Point2D &rhs) const {
        return !(*this < rhs);
    }

    Point2D &Point2D::operator+=(const Point2D &p) {
        this->x += p.x;
        this->y += p.y;
        return *this;
    }
} // Common