#include "complex.hpp"

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