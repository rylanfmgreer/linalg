#include <cmath>
#include <iostream>
#include "../complex_number.hpp"
#include "../utility_functions.hpp"
using namespace std;

double Complex::magnitude() const
{
    return sqrt(re * re + im * im);
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
    double prefactor = 1. / (re * re + im * im);
    double new_re = prefactor * re;
    double new_im = -prefactor * im;
    return Complex(new_re, new_im);
}

void Complex::print() const
{
    cout << re << " + " << im << 'i';
}

Complex Complex::copy() const
{
    return Complex(re, im);
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
    return create_complex_vector(re.data, im.data);
}
