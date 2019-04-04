#ifndef HEADER_H
#define HEADER_H

class Precise {
private:
    int size;

public:
    Precise();
    Precise(int size);
    int GetSize() const;
    Precise operator+(Precise& other) const;
    Precise operator-(Precise& other) const;
    Precise operator*(Precise& other) const;
    Precise operator/(Precise& other) const;
};

#endif // HEADER_H
