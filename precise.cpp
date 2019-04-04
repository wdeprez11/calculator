#include "header.h"
#include <bitset>

Precise::Precise()
{
}

Precise::Precise(int size)
    : size(size)
{
}

int Precise::GetSize() const
{
    return size;
}

Precise Precise::operator+(Precise& other) const
{
    return Precise(this->size + other.GetSize());
}

Precise Precise::operator-(Precise& other) const
{
    return Precise(this->size - other.GetSize());
}

Precise Precise::operator*(Precise& other) const
{
    return Precise(this->size * other.GetSize());
}

Precise Precise::operator/(Precise& other) const
{
    return Precise(this->size / other.GetSize());
}
