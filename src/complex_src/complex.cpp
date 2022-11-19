// author: rgreer
#include "complex_number.hpp"
#include <cmath>

Complex Complex::conjugate() const
{
    return Complex(this->re, -(this->im));
}

Complex Complex::conj() const
{
    return this->conjugate();
}

double Complex::angle() const
{
    double hyp = this->magnitude();
    return acos(re / hyp);
}

double Complex::theta() const
{
    return this->angle();
}