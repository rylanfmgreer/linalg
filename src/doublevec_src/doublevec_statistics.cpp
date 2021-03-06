#include "../doublevec.hpp"
#include <cmath>
using namespace std;

/*
    Statistics package for doublevecs.
    Includes doublevec level function as well as
    functions that can be called on 1 or 2 doublevecs (as appropriate.)
*/

// Sum
double DoubleVec::sum() const
{
    double s(0);
    for (int i(0); i < data.size(); ++i)
    {
        s += data[i];
    }
    return s;
}

double sum(const DoubleVec &v)
{
    return v.sum();
}

// Mean
double DoubleVec::mean() const
{
    return this->sum() / this->size();
}

double mean(const DoubleVec &v)
{
    return v.mean();
}

// Variance
double DoubleVec::var() const
{
    // population level, not sample level.
    // this must be manually adjusted for sample.
    double m(this->mean());
    double ssq(0);
    for (int i(0); i < data.size(); ++i)
    {
        double sq = (data[i] - m);
        ssq += sq * sq;
    }
    return ssq / data.size();
}

double var(const DoubleVec &v)
{
    return v.var();
}

// Standard Deviation
double DoubleVec::stdev() const
{
    // population level, not sample level.
    // this must be manually adjusted for sample.
    return sqrt(this->var());
}

double stdev(const DoubleVec &v)
{
    return v.stdev();
}

// Covariance
double DoubleVec::cov(const DoubleVec &v) const
{
    DoubleVec w = this->deep_copy();
    w = w - w.mean();

    DoubleVec y = v - v.mean();
    DoubleVec z = w.elementwise(y);
    return z.mean();
}

double cov(const DoubleVec &v, const DoubleVec &w)
{
    return v.cov(w);
}

// Correlation
double DoubleVec::cor(const DoubleVec &v) const
{
    double covariance = this->cov(v);
    double sd1 = this->stdev();
    double sd2 = v.stdev();
    return covariance / (sd1 * sd2);
}

double cor(const DoubleVec &v, const DoubleVec &w)
{
    return v.cor(w);
}

// Cumsum
DoubleVec DoubleVec::cumsum() const
{
    std::vector<double> new_vector(this->size());
    new_vector[0] = this->get(0);
    std::transform(new_vector.begin(), new_vector.end() - 1,
                   this->data.begin() + 1, new_vector.begin() + 1,
                   [](double x, double y)
                   { return x + y; });
    return DoubleVec(new_vector);
}

DoubleVec cumsum(const DoubleVec &v)
{
    return v.cumsum();
}