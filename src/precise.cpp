/**
  * TODO: Get working dynamic bitset for different creation by user
  */
#include "header.h"
#include <bitset>

/**
 * @brief construcst default size object
 * TODO: Actually figure out how to do dynamically sized bitsets (or at least be able to create them by different sizes)
 */
Precise::Precise()
{
}

/**
 * @brief construcst default size object
 * @param size The size of the bit array
 * TODO: Actually figure out how to do dynamically sized bitsets (or at least be able to create them by different sizes)
 */
Precise::Precise(int size)
    : size(size)
{
}

/**
  * @return Returns the size(length) of the bit array.
  */
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
