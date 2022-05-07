// author: rgreer

#ifndef complex_numbers_12903u1290
#define complex_numbers_12903u1290

#include <vector>
class Complex
{
public:
    /*
        Default (zero) initialization.
    */
    Complex();

    /*
        Initialize as x + yi
    */
    Complex(double x, double y);

    /*
        Initialize as x + 0i
    */
    Complex(double x); // re = x, im = 0

    /*
        Complex addition
        a + bi + c + di = (a + c) + (b + d)i
    */
    Complex operator+(const Complex &z) const;

    /*
        complex + double
        a + bi + c = (a + c) + bi
    */
    Complex operator+(double x) const;
    Complex operator+(int n) const;

    /*
        subtract a real scalar from a complex number
    */
    Complex operator-(double x) const;
    Complex operator-(int n) const;

    /*
        divide a complex number by a real scalar
    */
    Complex operator/(double x) const;

    /*
        Complex subtraction. pretty much addition in reverse
    */
    Complex operator-(const Complex &z) const;

    /*
        Test for equality
        z = a + bi
        w = c + di
        a == c & b == d
    */
    bool operator==(const Complex &z) const;

    /*
        simple negation of == operator.
    */
    bool operator!=(const Complex &z) const;

    /*
        Multiplication of two complex numbers
    */
    Complex operator*(const Complex &z) const;

    /*
        Scalar multiplication of a complex number
        x * (a + bi) = xa + xbi
    */
    Complex operator*(double x) const;

    /*
        Division of two complex numbers

    */
    Complex operator/(const Complex &z) const;

    /*
        returns the scalar magnitude of the complex number
    */
    double magnitude() const;

    /*
        for complex number z, returns w such that
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
        z = r * exp(it)
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
    double re;
    double im;
};

/*
    Given coefficients an, ..., a0, return anz^n + ... + a0
*/
Complex horner_polynomial(const std::vector<Complex> &v, const Complex z);

/*
    given coefficients an, ... a0 (real), return the roots of the polynomial
    anz^n + ... + a0
*/
std::vector<Complex> durand_kerner(const std::vector<double> &coefficients,
                                   double tolerance=1e-4,
                                   int n_iterations=1000);

/*
    turn a vector of real numbers into complex numbers
*/
std::vector<Complex> double_to_complex(
    const std::vector<double> &coefficients);

/*
    convert degrees to radians and vice versa
*/
double degrees_to_radians(double d);
double radians_to_degrees(double r);



#endif