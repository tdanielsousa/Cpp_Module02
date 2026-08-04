#include "Point.hpp"

/*
checks if point 'p' is on the left, right, or directly on the line p1->p2
*/
static Fixed crossProduct(Point const p1, Point const p2, Point const p)
{
    Fixed deltax1 = p2.getX() - p1.getX();
    Fixed deltay2 = p.getY() - p1.getY();
    Fixed deltay1 = p2.getY() - p1.getY();
    Fixed deltax2 = p.getX() - p1.getX();

    Fixed part1 = deltax1 * deltay2;
    Fixed part2 = deltay1 * deltax2;

    Fixed result = part1 - part2;

    return result;
}

/*
if point is on any edge or vertex (= 0) its not strictly inside
all 3 must be same sign to be inside
*/
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed cp1 = crossProduct(a, b, point);
    Fixed cp2 = crossProduct(b, c, point);
    Fixed cp3 = crossProduct(c, a, point);

    if (cp1 == 0 || cp2 == 0 || cp3 == 0)
    {
        return false;
    }

    if ((cp1 > 0 && cp2 > 0 && cp3 > 0) || (cp1 < 0 && cp2 < 0 && cp3 < 0))
    {
        return true;
    }

    return false;
}

/*
          C
         / \
        /   \
       /  *  \
      /   P   \
     /         \
    A-----------B

walk A to B: point P is on left (+)
walk B to C: point P is on left (+)
walk C to A: point P is on left (+)
its trapped inside
*/
