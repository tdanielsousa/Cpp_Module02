#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);

    std::cout << BBLUE << "a is " << BMAGENTA << a << std::endl;
    std::cout << BBLUE << "b is " << BMAGENTA << b << std::endl;
    std::cout << BBLUE << "c is " << BMAGENTA << c << std::endl;
    std::cout << BBLUE << "d is " << BMAGENTA << d << std::endl;

    std::cout << BBLUE << "a is " << BMAGENTA << a.toInt() << BBLUE << " as integer"
              << std::endl;
    std::cout << BBLUE << "b is " << BMAGENTA << b.toInt() << BBLUE << " as integer"
              << std::endl;
    std::cout << BBLUE << "c is " << BMAGENTA << c.toInt() << BBLUE << " as integer"
              << std::endl;
    std::cout << BBLUE << "d is " << BMAGENTA << d.toInt() << BBLUE << " as integer"
              << std::endl;

    return 0;
}