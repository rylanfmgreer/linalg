// author: rgreer

#pragma once
#ifndef complex_numbers_12903u1290
#define complex_numbers_12903u1290

#include <vector>
#include "../utilities_src/utility_functions.hpp"
#include "../doublevec_src/doublevec.hpp"

class Complex
{
public:
    /*
        Default (zero) initialization.
    */
    Complex();

    /*
        Initialize as p_x + yi
    */
    Complex(double p_x, double p_y);

    /*
        Initialize as p_x + 0i
    */
    Complex(double p_x); // p_re = p_x, p_im = 0

    /*
        Complex addition
        a + bi + c + di = (a + c) + (b + d)i
    */
    Complex operator+(const Complex &p_z) const;

    /*
        complex + double
        a + bi + c = (a + c) + bi
    */
    Complex operator+(double p_x) const;
    Complex operator+(int p_n) const;

    /*
        subtract a real scalar from a complex number
    */
    Complex operator-(double p_x) const;
    Complex operator-(int p_n) const;

    /*
        divide a complex number by a real scalar
    */
    Complex operator/(double p_x) const;

    /*
        Complex subtraction. pretty much addition in reverse
    */
    Complex operator-(const Complex &p_z) const;

    /*
        Test for equality
        p_z = a + bi
        w = c + di
        a == c & b == d
    */
    bool operator==(const Complex &p_z) const;
    
    /*
        p_z = a + bi
        a == x & b == 0
    */
    bool operator==(const double p_x) const;

    /*
        simple negation of == operator.
    */
    bool operator!=(const Complex &p_z) const;

    /*
        Multiplication of two complex numbers
    */
    Complex operator*(const Complex &p_z) const;

    /*
        Scalar multiplication of a complex number
        x * (a + bi) = xa + xbi
    */
    Complex operator*(double p_x) const;

    /*
        Division of two complex numbers

    */
    Complex operator/(const Complex &p_z) const;

    /*
        returns the scalar magnitude of the complex number
    */
    double magnitude() const;

    /*
        for complex number p_z, returns w such that
        wz = zw = 1
    */
    Complex inverse() const;

    /*
        Returns the complex number's conjugate
    */
    Complex conjugate() const;
    Complex conj() const;

    /*
        For a complex number z,
        z = p_r * exp(it)
        return t in [0, 2 * pi)
    */
    double angle() const;
    double theta() const;

    /*
        Returns a copy of the complex number
    */
    Complex copy() const;

    /*
        Prints the complex number in a readable way
    */
    void print() const;

    // the real and imaginary components of the number.
    double m_re;
    double m_im;
};

/*
    Given p_coefficients an, ..., a0, return anz^n + ... + a0
*/
Complex horner_polynomial(const std::vector<Complex> &v, const Complex z);

/*
    given p_coefficients an, ... a0 (real), return the roots of the polynomial
    anz^n + ... + a0
*/
std::vector<Complex> durand_kerner(const std::vector<double> &p_coefficients,
                                   double p_tolerance=1e-4,
                                   int p_n_iterations=1000);

/*
    turn a vector of real numbers into complex numbers
*/
std::vector<Complex> double_to_complex(
    const std::vector<double> &p_coefficients);

/*
    turn two vectors of real numbers into a vector of
    complex numbers
*/
std::vector<Complex> create_complex_vector(
    const std::vector<double> &p_re, 
    const std::vector<double> &p_im);

std::vector<Complex> create_complex_vector(
    const DoubleVec &p_re, const DoubleVec &p_im);

/*
    convert degrees to radians and vice versa
*/
double degrees_to_radians(double p_d);
double radians_to_degrees(double p_r);



#endif