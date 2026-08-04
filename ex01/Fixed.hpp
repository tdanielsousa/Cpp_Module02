#ifndef FIXED_HPP
#define FIXED_HPP

#define RESET "\033[0m"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#define BRED "\033[1;31m"
#define BGREEN "\033[1;32m"
#define BYELLOW "\033[1;33m"
#define BBLUE "\033[1;34m"
#define BMAGENTA "\033[1;35m"
#define BCYAN "\033[1;36m"

#include <iostream>
#include <cmath>

class Fixed
{
  private:
    int _value;
    static const int _fractionalBits = 8;

  public:
    // Orthodox Canonical Form
    Fixed(void);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed(void);

    // int and float new constructors
    Fixed(const int intVal);
    Fixed(const float floatVal);

    // member functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

/*
std::cout << a;  
cpp transform that into operator<<(std::cout, a);
stream insertion operator overload
*/
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif