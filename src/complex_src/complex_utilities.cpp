#include <cmath>
#include <iostream>
#include "complex_number.hpp"
#include "../utilities_src/utility_functions.hpp"
using namespace std;

double Complex::magnitude() const
{
    return sqrt(m_re * m_re + m_im * m_im);
}

Complex Complex::inverse() const
{
    /*
        (a + bi) * (c + di) = 1 + 0ir
        ac - bd = 1
        ad + bc = 0
        [a b] c = 1
        [b a] d   0
    */
    assert(this->magnitude() > 0.);
    double prefactor = 1. / (m_re * m_re + m_im * m_im);
    double new_re = prefactor * m_re;
    double new_im = -prefactor * m_im;
    return Complex(new_re, new_im);
}

void Complex::print() const
{
    cout << m_re << " + " << m_im << 'i';
}

Complex Complex::copy() const
{
    return Complex(m_re, m_im);
}

std::vector<Complex> double_to_complex(const std::vector<double> &coefficients)
{
    vector<Complex> new_coeffs(coefficients.size());
    transform(coefficients.begin(), coefficients.end(), new_coeffs.begin(),
              [](double x)
              { return Complex(x, 0); });
    return new_coeffs;
}

double radian_to_degrees(double r)
{
    double x = (360. / (2. * M_PI));
    return r * x;
}

double degrees_to_radian(double d)
{
    double x = 2 * M_PI / 360.;
    return d * x;
}

std::vector<Complex> create_complex_vector(
    const std::vector<double> &re, 
    const std::vector<double> &im)
{
    assert( re.size() == im.size() );
    std::vector<Complex> out(re.size());

    std::transform(re.begin(), re.end(),
                   im.begin(), out.begin(),
                   [](double x, double y){
                       return Complex(x, y);
                   }
    );
    return out;
}

std::vector<Complex> create_complex_vector(
    const DoubleVec &re, const DoubleVec &im)
{
    return create_complex_vector(re.m_data, im.m_data);
}
