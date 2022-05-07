// author: rgreer
#include "complex_number.hpp"
#include <cmath>

Complex Complex::conjugate() const
{
    new_re = this->re;
    new_im = -(this->im);
    return Complex( new_re, new_im );
}

Complex Complex::conj() const
{
    return this->conjugate();
}

double Complex::angle() const
{
    double hyp = this->magnitude();
    return acos( re/hyp );
}

double Complex::theta() const
{
    return this->angle();
}