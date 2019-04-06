#ifndef HEADER_H
#define HEADER_H
#include <bitset>

class Precise {
private:
    int size;
    std::bitset<512> preciseBits;

public:
    Precise();
    Precise(int size);
    int get_size() const;
    Precise operator+(Precise& other) const;
    Precise operator-(Precise& other) const;
    Precise operator*(Precise& other) const;
    Precise operator/(Precise& other) const;
};

#endif // HEADER_H
