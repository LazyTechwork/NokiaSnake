
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

    Point2D Point2D::fromDirection(Direction &direction) {
        switch (direction) {
            case Direction::UP:
                return {0, 1};
            case Direction::DOWN:
                return {0, -1};
            case Direction::RIGHT:
                return {1, 0};
            case Direction::LEFT:
                return {-1, 0};
        }

        return {0, 0};
    }
} // Common