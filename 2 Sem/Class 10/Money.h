#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Money {
private:
    long rub;
    int kop;

public:
    Money();
    Money(long r, int k);
    Money(const Money& other);
    ~Money();

    long getRub() const;
    int getKop() const;

    void setRub(long r);
    void setKop(int k);

    void Show() const;

    Money operator/(const Money& other) const;
    Money operator*(double factor) const;
    Money operator/(int divisor) const;

    bool operator==(const Money& other) const;
    bool operator!=(const Money& other) const;

    friend std::istream& operator>>(std::istream& in, Money& m);
    friend std::ostream& operator<<(std::ostream& out, const Money& m);
    friend std::fstream& operator>>(std::fstream& fin, Money& m);
    friend std::fstream& operator<<(std::fstream& fout, const Money& m);
};