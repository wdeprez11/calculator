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
