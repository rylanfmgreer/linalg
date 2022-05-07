#include "doublevec.hpp"
#include "utility_functions.hpp"
using namespace std;
using namespace util;

DoubleVec DoubleVec::operator+(const DoubleVec &v) const
{
    // Elementwise (vector) addition of two vectors.
    assert(data.size() == v.data.size());
    vector<double> new_vector(v.data.size());
    transform(data.begin(), data.end(),
              v.data.begin(), new_vector.begin(),
              [](double x, double y)
              { return x + y; });
    return DoubleVec(new_vector);
}

DoubleVec DoubleVec::operator+(const double scalar) const
{
    // Addition of a constant to a vector, as in numpy
    vector<double> new_vector(data.size());
    transform(data.begin(), data.end(), new_vector.begin(),
              [scalar](double x)
              { return x + scalar; });
    return DoubleVec(new_vector);
}

DoubleVec DoubleVec::operator*(const double scalar) const
{
    // Scalar product of a vector and a scalar.
    vector<double> new_vector(data.size());
    transform(data.begin(), data.end(), new_vector.begin(),
              [scalar](double x)
              { return x * scalar; });
    return DoubleVec(new_vector);
}

DoubleVec DoubleVec::operator-(const DoubleVec &v) const
{
    // Vector subtraction.
    assert(data.size() == v.data.size());
    return *this + (v * -1.);
}

DoubleVec DoubleVec::operator-(const double scalar) const
{
    // similar to addition of a scalar... but in reverse.
    return *this + (-1. * scalar);
}

double DoubleVec::operator*(const DoubleVec &v) const
{
    // Dot product: R^n x R^n -> R
    assert(data.size() == v.size());
    double s(0);
    for (int i(0); i < v.size(); ++i)
    {
        s += data[i] * v.data[i];
    }
    return s;
}

double &DoubleVec::operator[](int n)
{
    // simple indexing
    assert(data.size() > n);
    return data[n];
}

bool DoubleVec::operator==(const DoubleVec &v) const
{
    // elementwise equality
    if (v.size() != data.size())
        return false;

    for (int i(0); i < v.size(); ++i)
    {
        if (!close(v.get(i), data[i]))
            return false;
    }
    return true;
}

bool DoubleVec::operator!=(const DoubleVec &v) const
{
    if (v.size() != data.size())
        return true;
    for (int i(0); i < v.size(); ++i)
    {
        if (!close(v.get(i), data[i]))
            return true;
    }
    return false;
}