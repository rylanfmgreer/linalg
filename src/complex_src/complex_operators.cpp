#include "complex_number.hpp"
using namespace std;

Complex Complex::operator+(const Complex &z) const
{
    double new_re = this->m_re + z.m_re;
    double new_im = this->m_im + z.m_im;
    return Complex(new_re, new_im);
}

Complex Complex::operator-(const Complex &z) const
{
    double new_re = this->m_re - z.m_re;
    double new_im = this->m_im - z.m_im;
    return Complex(new_re, new_im);
}

Complex Complex::operator+(const double x) const
{
    return Complex(m_re + x, m_im);
}

Complex Complex::operator+(const int n) const
{
    return Complex(m_re + n, m_im);
}

Complex Complex::operator-(const double x) const
{
    return (*this) + (-x);
}

Complex Complex::operator-(const int n) const
{
    return (*this) + (-n);
}

Complex Complex::operator*(const Complex &z) const
{
    double new_re = this->m_re * z.m_re - this->m_im * z.m_im;
    double new_im = this->m_re * z.m_im + this->m_im * z.m_re;
    return Complex(new_re, new_im);
}

Complex Complex::operator*(double x) const
{
    double new_re = x * this->m_re;
    double new_im = x * this->m_im;
    return Complex(new_re, new_im);
}

Complex Complex::operator/(double x) const
{
    double new_re = this->m_re / x;
    double new_im = this->m_im / x;
    return Complex(new_re, new_im);
}

Complex Complex::operator/(const Complex &z) const
{
    Complex w = z.inverse();
    return (*this) * w;
}

bool Complex::operator==(const Complex &z) const
{
    return util::close(m_re, z.m_re) && util::close(m_im, z.m_im);
}

bool Complex::operator==(const double x) const
{
    return util::close(m_re, x) && util::close(m_im, 0.);
}

bool Complex::operator!=(const Complex &z) const
{
    return (m_re != z.m_re) || (m_im != z.m_im);
}