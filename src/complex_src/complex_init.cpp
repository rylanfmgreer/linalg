#include "complex_number.hpp"

Complex::Complex()
{
    m_re = 0;
    m_im = 0;
}

Complex::Complex(double x, double y)
{
    m_re = x;
    m_im = y;
}

Complex::Complex(double x)
{
    m_re = x;
    m_im = 0;
}