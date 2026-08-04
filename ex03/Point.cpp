#include "Point.hpp"

// constructor
Point::Point(void) : _x(0), _y(0)
{
}

// constructor with x and y
Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

// copy constructor
Point::Point(const Point& other) : _x(other._x), _y(other._y)
{
}

// copy assignment operator const attributes cannot be assigned to
Point& Point::operator=(const Point& other)
{
    (void)other;
    return *this;
}

Point::~Point(void)
{
}

///////////////////////////////
// Accessors
////////////////////////////
Fixed Point::getX(void) const
{
    return this->_x;
}

Fixed Point::getY(void) const
{
    return this->_y;
}
