#include <cmath>
#include "../doublevec.hpp"

using namespace std;

void DoubleVec::print()
{
    for (int i(0); i < data.size(); ++i)
    {
        cout << data[i] << ' ';
    }
}

DoubleVec DoubleVec::elementwise(const DoubleVec &w) const
{
    // Elementwise (or Hadamard) product of two vectors.
    assert(this->size() == w.size());
    vector<double> new_vector(this->size());
    transform(data.begin(), data.end(),
              w.data.begin(), new_vector.begin(),
              [ ](double x, double y)
              { return x * y; });
    return DoubleVec(new_vector);
}

DoubleVec DoubleVec::deep_copy() const
{
    vector<double> new_vector(this->size());
    copy(data.begin(), data.end(), new_vector.begin());
    return DoubleVec(new_vector);
}

DoubleVec DoubleVec::apply(function<double(double)> f) const
{
    // Apply a unary function to every element of a vector.
    vector<double> new_vector(data.size());
    transform(data.begin(), data.end(), new_vector.begin(), f);
    return DoubleVec(new_vector);
}

DoubleVec DoubleVec::concat(const DoubleVec &v) const
{
    // Concatenate two vectors.
    // The "calling vector" is first and the "input vector" is second.
    vector<double> new_vec(this->size() + v.size());
    copy(this->data.begin(), this->data.end(), new_vec.begin());
    copy(v.data.begin(), v.data.end(), new_vec.begin() + this->size());
    return DoubleVec(new_vec);
}

DoubleVec DoubleVec::sort() const
{
    DoubleVec new_vec = this->deep_copy();
    std::sort(new_vec.data.begin(), new_vec.data.end());
    return new_vec;
}

bool DoubleVec::is_in(double v) const
{
    for (int i(0); i < data.size(); ++i)
    {
        if (data[i] == v)
            return true;
    }
    return false;
}

double DoubleVec::get(int r) const
{
    return data[r];
}

int DoubleVec::count(double v, double eps) const
{
    int c(0);
    for (int i(0); i < this->size(); ++i)
    {
        if (std::abs(data[i] - v) < eps)
            c++;
    }
    return c;
}

DoubleVec DoubleVec::drop_index(int n) const
{
    DoubleVec new_vec = this->deep_copy();
    new_vec.data.erase(new_vec.data.begin() + n);
    return new_vec;
}

DoubleVec DoubleVec::drop_index(std::vector<int> v) const
{
    // sort v as descending
    std::sort(v.begin(), v.end(), greater<int>());
    DoubleVec new_vec = this->deep_copy();
    for (int i(0); i < v.size(); ++i)
    {
        new_vec.data.erase(new_vec.data.begin() + v[i]);
    }
    return new_vec;
}

double DoubleVec::sq_norm() const
{
    double s(0);
    double x;
    for( int i(0); i < this->size(); ++i )
    {
        x = this->get(i);
        s += x * x;
    }
    return sqrt(s);
}

double DoubleVec::norm() const
{
    return sqrt( this->sq_norm() );
}