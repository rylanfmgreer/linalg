#include <cmath>
#include <float.h>
#include "doublevec.hpp"
#include <algorithm>

using namespace std;

void DoubleVec::print()
{
    for (int i(0); i < m_data.size(); ++i)
    {
        cout << m_data[i] << ' ';
    }
}

DoubleVec DoubleVec::elementwise_multiply(const DoubleVec &w) const
{
    // Elementwise (or Hadamard) product of two vectors.
    assert(this->size() == w.size());
    vector<double> new_vector(this->size());
    transform(m_data.begin(), m_data.end(),
              w.m_data.begin(), new_vector.begin(),
              [ ](double x, double y)
              { return x * y; });
    return DoubleVec(new_vector);
}

DoubleVec DoubleVec::deep_copy() const
{
    vector<double> new_vector(this->size());
    copy(m_data.begin(), m_data.end(), new_vector.begin());
    return DoubleVec(new_vector);
}

DoubleVec DoubleVec::apply(function<double(double)> f) const
{
    // Apply a unary function to every element of a vector.
    vector<double> new_vector(m_data.size());
    transform(m_data.begin(), m_data.end(), new_vector.begin(), f);
    return DoubleVec(new_vector);
}

DoubleVec DoubleVec::concat(const DoubleVec &v) const
{
    // Concatenate two vectors.
    // The "calling vector" is first and the "input vector" is second.
    vector<double> new_vec(this->size() + v.size());
    copy(this->m_data.begin(), this->m_data.end(), new_vec.begin());
    copy(v.m_data.begin(), v.m_data.end(), new_vec.begin() + this->size());
    return DoubleVec(new_vec);
}

DoubleVec DoubleVec::sort() const
{
    DoubleVec new_vec = this->deep_copy();
    std::sort(new_vec.m_data.begin(), new_vec.m_data.end());
    return new_vec;
}

bool DoubleVec::is_in(double v) const
{
    for (int i(0); i < m_data.size(); ++i)
    {
        if (m_data[i] == v)
            return true;
    }
    return false;
}

double DoubleVec::get(int r) const
{
    return m_data[r];
}

int DoubleVec::count(double v, double eps) const
{
    int c(0);
    for (int i(0); i < this->size(); ++i)
    {
        if (std::abs(m_data[i] - v) < eps)
            c++;
    }
    return c;
}

DoubleVec DoubleVec::drop_index(int n) const
{
    DoubleVec new_vec = this->deep_copy();
    new_vec.m_data.erase(new_vec.m_data.begin() + n);
    return new_vec;
}

DoubleVec DoubleVec::drop_index(std::vector<int> v) const
{
    // sort v as descending
    std::sort(v.begin(), v.end(), greater<int>());
    DoubleVec new_vec = this->deep_copy();
    for (int i(0); i < v.size(); ++i)
    {
        new_vec.m_data.erase(new_vec.m_data.begin() + v[i]);
    }
    return new_vec;
}

double DoubleVec::sq_norm() const
{
    double sum_squares(0.);
    std::for_each(m_data.begin(), m_data.end(),
                  [&sum_squares](double x)
                  { sum_squares += x * x; }
    );
    return sum_squares;
}

double DoubleVec::norm() const
{
    return sqrt( this->sq_norm() );
}

double DoubleVec::dot(const DoubleVec& v) const
{
    return *this * v;
}

DoubleVec DoubleVec::normalize() const
{
    double dv_sum = sum();
    assert( abs(dv_sum) > 1e-10 );
    DoubleVec new_dv = this->deep_copy();
    return (1.0 / dv_sum) * new_dv;
}

void DoubleVec::normalize_inplace()
{
    double dv_sum = sum();
    assert( abs(dv_sum) > 1e-10 );
    std::transform(m_data.begin(), m_data.end(), m_data.begin(),
                  [dv_sum]( double x ){ return x / dv_sum; });
}