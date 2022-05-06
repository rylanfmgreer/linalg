#include "complex_number.hpp"
#include <cmath>
#include <iostream>
using namespace std;

double Complex::magnitude() const
{
    return sqrt( re * re + im * im );

}
Complex Complex::inverse() const
{
    /*
        (a + bi) * (c + di) = 1 + 0i
        ac - bd = 1
        ad + bc = 0
        [a b] c = 1
        [b a] d   0
    */
   assert( this->magnitude() > 0. );
   double prefactor = 1. / (re * re + im * im);
   double new_re    = prefactor * re;
   double new_im    = -prefactor * im; 
   return Complex( new_re, new_im );
}

void Complex::print() const
{
    cout << re << " + " << im << 'i';

}

Complex Complex::copy() const
{
    return Complex( re, im );
}

std::vector< Complex > double_to_complex( const std::vector<double>& coefficients)
{
    vector< Complex > new_coeffs( coefficients.size() );
    transform( coefficients.begin(), coefficients.end(), new_coeffs.begin(),
               []( double x ){ return Complex( x, 0 ); });
    return new_coeffs;
}