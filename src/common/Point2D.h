#ifndef NOKIASNAKE_POINT2D_H
#define NOKIASNAKE_POINT2D_H

#include <cstdint>

namespace Common {

    struct Point2D {
        int16_t x;
        int16_t y;

        Point2D operator+(Point2D p) const;
        Point2D& operator+=(const Point2D& p);

        bool operator==(const Point2D &rhs) const;

        bool operator!=(const Point2D &rhs) const;

        bool operator<(const Point2D &rhs) const;

        bool operator>(const Point2D &rhs) const;

        bool operator<=(const Point2D &rhs) const;

        bool operator>=(const Point2D &rhs) const;
    };

} // Common

#endif //NOKIASNAKE_POINT2D_H
