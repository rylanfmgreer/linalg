// author: rgreer
#include "complex_number.hpp"
#include <cmath>

Complex Complex::conjugate() const
{
    return Complex(this->m_re, -(this->m_im));
}

Complex Complex::conj() const
{
    return this->conjugate();
}

double Complex::angle() const
{
    double hyp = this->magnitude();
    return acos(m_re / hyp);
}

double Complex::theta() const
{
    return this->angle();
}