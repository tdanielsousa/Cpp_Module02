#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
    std::cout << BCYAN << "Default constructor called\n" << RESET;
}

// copy (birth by cloning 'other')
// doesnt show the line of subject due to direct initialization, no operator=
Fixed::Fixed(const Fixed& other)
{
    std::cout << BGREEN << "Copy constructor called\n" << RESET;
    this->_value = other.getRawBits();
}

// copy assign (overwriting 'this' with 'other')
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << BMAGENTA << "Copy assignment operator called\n" << RESET;
    if (this != &other)
    {
        this->_value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << BRED << "Destructor called\n" << RESET;
}

/////////////////////////////////////////////////////////
// accessors
/////////////////////////////////////////////////////////
int Fixed::getRawBits(void) const
{
    std::cout << BBLUE << "getRawBits member function called\n" << RESET;
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}
