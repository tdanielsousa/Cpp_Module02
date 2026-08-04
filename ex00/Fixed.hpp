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

/*
// Orthodox Canonical Form Requirements

Copy Constructor
2 sintaxes > Fixed b(a); or Fixed b = a;  (Cloning 'a')
  creating a brand-new b object from scratch and giving it all
    of a's values, requires a to exist before

Copy Assignment	b = a; (both exist)	(overwriting 'b')
 both need to already exist and it wipes b data and gives it all of a values

*/
class Fixed
{
  private:
    int _value;
    static const int _fractionalBits = 8;

  public:
    Fixed(void);
    Fixed(const Fixed& other);            // copy (birth by cloning 'other')
    Fixed& operator=(const Fixed& other); // copy assign (overwriting 'this' with 'other')
    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif