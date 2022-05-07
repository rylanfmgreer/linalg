#include "complex_number.hpp"
using namespace std;

Complex Complex::operator+(const Complex& z ) const
{
    double new_re = this->re + z.re;
    double new_im = this->im + z.im;
    return Complex( new_re, new_im );
}


Complex Complex::operator-(const Complex& z ) const
{
    double new_re = this->re - z.re;
    double new_im = this->im - z.im;
    return Complex( new_re, new_im );
}


Complex Complex::operator*( const Complex& z) const
{
    double new_re = this->re * z.re - this->im * z.im;
    double new_im = this->re * z.im + this->im * z.re;
    return Complex( new_re, new_im );
}


Complex Complex::operator*( double x) const
{
    double new_re = x * this->re;
    double new_im = x * this->im;
    return Complex( new_re, new_im );
}


Complex Complex::operator+( double x ) const
{
    double new_re = this->re + x;
    double new_im = this->im;
    return Complex( new_re, new_im );
}


Complex Complex::operator/( double x) const
{
    double new_re = this->re / x;
    double new_im = this->im / x;
    return Complex( new_re, new_im );
}


Complex Complex::operator/( const Complex& z) const
{
    Complex w = z.inverse();
    return (*this) * w;
}


bool Complex::operator==( const Complex& z) const
{
    return (re == z.re) && (im == z.im);
}


bool Complex::operator!=( const Complex& z ) const
{
    return (re != z.re) || (im != z.im);
}