#ifndef normal_dist_rg___
#define normal_dist_rg___

#include "distribution.hpp"

class NormalDistribution: public UnivariateDistribution
{
    public:
    NormalDistribution(double p_mean=0., double p_variance=1.);
    double mgf(double p_x) const;
    double cdf(double p_x) const;
    double pdf(double p_x) const;
    double inv_cdf(double p_x) const;
    
    double median() const;
    double expectation() const;
    double variance() const;

    private:
    double m_mean;
    double m_variance;
    double m_sigma; // reduce computation
};

#endif