#include "complex_number.hpp"
#include <iostream>
using namespace std;

std::vector<Complex> durand_kerner(const std::vector<double> &coefficients)
{
    // https://en.wikipedia.org/wiki/Durand%E2%80%93Kerner_method
    // no trickery -- let's not assume the leading coefficient is 1
    vector<Complex> old_roots(coefficients.size() - 1);
    vector<Complex> new_roots(coefficients.size() - 1);
    vector<Complex> complex_coefficients(coefficients.size());
    double tolerance = 1e-4;
    int n_iterations = 1000;

    // set up initial guesses
    Complex root = Complex(1, 0);
    Complex mult = Complex(0.4, 0.9);
    Complex fx;
    Complex denominator;

    // set up initial guesses for roots
    for (int i(0); i < old_roots.size(); ++i)
    {
        old_roots[i] = root;
        root = root * mult;
    }

    // set up complex coefficients for polynomial with leading 1
    double fc = coefficients[0];
    transform(coefficients.begin(), coefficients.end(), complex_coefficients.begin(),
              [fc](double x)
              { return Complex(x / fc, 0); });

    // algorithm
    for (int i(0); i < n_iterations; ++i)
    {
        for (int j(0); j < old_roots.size(); ++j)
        {
            fx = horner_polynomial(complex_coefficients, old_roots[j]);
            denominator = Complex(1, 0);
            for (int k(0); k < old_roots.size(); ++k)
            {
                if (k != j)
                {
                    denominator = denominator * (old_roots[j] - old_roots[k]);
                }
            }
            // p_j = p_{j - 1} - f(p_{j - 1}) / [( p_{j - 1} - q_{j - 1})  * ... * (p_{j - 1} - z_{j - 1})]
            new_roots[j] = old_roots[j] - (fx / denominator);
        }

        // copy the "new roots" into "old roots"
        for (int j(0); j < old_roots.size(); ++j)
        {
            old_roots[j] = new_roots[j];
        }
    }
    return new_roots;
}