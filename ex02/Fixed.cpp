#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
    std::cout << BGREEN << "Default constructor called\n" << RESET;
}

/*
int constructor bit-shift left by 8 bits equal to multiply by 256
*/
Fixed::Fixed(const int intVal)
{
    std::cout << BGREEN << "Int constructor called\n" << RESET;
    this->_value = intVal << _fractionalBits;
}

/*
float constructor multiply by 256 and round to int
*/
Fixed::Fixed(const float floatVal)
{
    std::cout << BGREEN << "Float constructor called\n" << RESET;
    this->_value = roundf(floatVal * (1 << _fractionalBits));
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
    std::cout << BGREEN << "Copy assignment operator called\n" << RESET;
    if (this != &other)
    {
        this->_value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << BGREEN << "Destructor called\n" << RESET;
}

////////////////////////////////////////////////////////////////////////
// accessors
////////////////////////////////////////////////////////////////////////
int Fixed::getRawBits(void) const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

////////////////////////////////////////////////////////////////////////
// conversions
////////////////////////////////////////////////////////////////////////
/*
1 << 8 gives 2^8 = 256
cast so cpp doesnt perform integer division
*/
float Fixed::toFloat(void) const
{
    float scaleFactor = (float)(1 << _fractionalBits);

    float rawAsFloat = (float)this->_value;

    float result = rawAsFloat / scaleFactor;

    return result;
}

/*
fixed-point arithmetic with 8 bits raw value is scaled up by 256
drops the decimal part and leaves only int
divide by 256
*/
int Fixed::toInt(void) const
{
    int rawValue = this->_value;

    int integerPart = rawValue >> _fractionalBits;

    return integerPart;
}

/////////////////////////////////////////////////////
// comparison operators
//////////////////////////////////////////////////////
bool Fixed::operator>(const Fixed& other) const
{
    return this->_value > other._value;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->_value != other._value;
}

//////////////////////////////////////////////////////////
// arithmetic operators
//////////////////////////////////////////////////////////
Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->_value + other._value);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->_value - other._value);
    return result;
}

/*
 raw fixed-point multiplication formula ((raw_A * raw_B) / 256
*/
Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

/*
 raw fixed-point division formula ((raw_A * 256) / raw_B)
*/
Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

//////////////////////////////////////////////////////////
// increment and decrement opperators
//////////////////////////////////////////////////////////
/*
pre-increments need & because they acess an already existing obj
definition of post-increment (a++) in programming:
a++ must give back the old value but leave a containing the NEW value
*/
Fixed& Fixed::operator++(void)
{
    this->_value += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_value += 1;
    return temp;
}

Fixed& Fixed::operator--(void)
{
    this->_value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_value -= 1;
    return temp;
}

//////////////////////////////////////////////////////////
// static min / max overloads
//////////////////////////////////////////////////////////
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    return b;
}

/*
////////////////////////////////////////////////////////////////////////
insertion operator overload
eliminates the need to do a.tofloat
std::cout << a.toFloat();  becomes  std::cout << a;
////////////////////////////////////////////////////////////////////////
*/
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
