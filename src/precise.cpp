#include "header.h"
#include <bitset>

/**
 *
 */
Precise::Precise()
{
}

Precise::Precise(int size)
    : size(size)
{
}

int Precise::get_size() const
{
    return size;
}

/**
  * @brief Preforms addition on two Precise objects
  * @param other The other Precise object for the function
  * @return Returns the sum of two Precise objects
  */
Precise Precise::operator+(Precise& other) const
{
    return Precise(this->size + other.size);
}

/**
  * @brief Preforms subtraction on two Precise objects
  * @param other The other Precise object for the function
  * @return Returns the difference between the first Precise object subtracted by the second Precise object
  */
Precise Precise::operator-(Precise& other) const
{
    return Precise(this->size - other.size);
}

/**
  * @brief Multiplies two product objects and returns a Precise object
  * @param other The other Precise object for the function
  * @return Returns the product of both Precise objects
  */
Precise Precise::operator*(Precise& other) const
{
    return Precise(this->size * other.size);
}

/**
  * @brief Takes the first Precise object as the divisor, and the parameter as the dividend
  * @param other The other Precise object for the function
  * @return Returns the quotient of the first Precise object as the divisor and the second Precise as the dividend
  */
Precise Precise::operator/(Precise& other) const
{
    return Precise(this->size / other.size);
}
