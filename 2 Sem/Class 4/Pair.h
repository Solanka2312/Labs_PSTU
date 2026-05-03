#pragma once
#include <iostream>
class Pair {
protected:
    int first;
    int second;
public:
    Pair();
    Pair(int f, int s);
    Pair(const Pair& other);
    virtual ~Pair();

    void setFirst(int f);
    void setSecond(int s);

    int getFirst() const;
    int getSecond() const;

    virtual void Show() const;

    bool operator>(const Pair& other) const;
    bool operator<(const Pair& other) const;
    bool operator==(const Pair& other) const;
    bool operator!=(const Pair& other) const;
    bool operator>=(const Pair& other) const;
    bool operator<=(const Pair& other) const;

    Pair& operator=(const Pair& other);
    friend std::istream& operator>>(std::istream& in, Pair& p);
    friend std::ostream& operator<<(std::ostream& out, const Pair& p);
};