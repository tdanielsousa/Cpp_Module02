#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void testPoint(std::string name, Point const a, Point const b, Point const c, Point const p,
               bool expected)
{
    bool result = bsp(a, b, c, p);

    std::string resultStr;

    if (result == true)
        resultStr = YELLOW "Inside" RESET;
    else
        resultStr = YELLOW "Outside/Edge" RESET;

    std::string expectedStr;

    if (expected == true)
        expectedStr = YELLOW "Inside" RESET;
    else
        expectedStr = YELLOW "Outside/Edge" RESET;

    std::string statusStr;

    if (result == expected)
        statusStr = BGREEN "[OK]" RESET;
    else
        statusStr = BRED "[FAIL]" RESET;

    std::cout << BMAGENTA << name << RESET;
    std::cout << BLUE << "Result: " << RESET << resultStr << "\n";
    std::cout << BLUE << "Expected: " << RESET << expectedStr << "\n";
    std::cout << BLUE << "STATUS: " << RESET << statusStr << "\n";

    return;
}

int main(void)
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    std::cout << BCYAN << "************************\n";
    std::cout << "**** BSP Unit Tests ****\n";
    std::cout << "************************\n" << RESET;

    // inside
    testPoint("point strictly inside:\n", a, b, c, Point(2.0f, 2.0f), true);

    // outside
    testPoint("point outside, far:\n", a, b, c, Point(15.0f, 15.0f), false);
    testPoint("point outside, near the edge:\n", a, b, c, Point(-1.0f, 1.0f), false);

    // on a vertex
    testPoint("point on vertex a:\n", a, b, c, Point(0.0f, 0.0f), false);

    // on edge
    testPoint("point on edge:\n", a, b, c, Point(5.0f, 5.0f), false);
    testPoint("point on bottom edge:\n", a, b, c, Point(5.0f, 0.0f), false);

    return 0;
}
