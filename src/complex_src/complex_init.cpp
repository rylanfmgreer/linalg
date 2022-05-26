#include "../complex_number.hpp"

Complex::Complex()
{
    re = 0;
    im = 0;
}

Complex::Complex(double x, double y)
{
    re = x;
    im = y;
}

Complex::Complex(double x)
{
    re = x;
    im = 0;
}