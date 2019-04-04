#include "header.h"

Precise::Precise()
    : size(8)
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
