#pragma once
#include "Pair.h"
class Fraction : public Pair {
public:
    Fraction();
    Fraction(int integer, int decimal);
    Fraction(const Fraction& other);
    ~Fraction();

    bool operator>(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;

    Fraction& operator=(const Fraction& other);

    void Show() const override;
    friend std::istream& operator>>(std::istream& in, Fraction& f);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};