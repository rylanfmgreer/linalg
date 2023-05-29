#include "normal.hpp"
#include <float.h>
#include <cmath>

NormalDistribution::NormalDistribution(double p_mean, double p_variance)
:m_mean(p_mean), m_variance(p_variance)
{
    m_lower_bound= -DBL_MAX;
    m_upper_bound = DBL_MAX;
    m_sigma = sqrt(m_variance);
}

double NormalDistribution::pdf(double p_x) const
{

    double prefactor = 1. / (m_sigma * sqrt(2. * M_PI));
    double z = (p_x - m_mean) / m_sigma;
    return prefactor * exp( -0.5 * z * z );

}

double NormalDistribution::expectation() const
{
    return m_mean;
}

double NormalDistribution::variance() const
{
    return m_variance;
}

double NormalDistribution::cdf(double p_x) const
{
    // https://stackoverflow.com/questions/2328258/cumulative-normal-distribution-function-in-c-c
    return 0.5 * erfc( -p_x * M_SQRT1_2);
}

double NormalDistribution::mgf(double p_t) const
{
    return exp( m_mean * p_t + 0.5 * m_variance * p_t * p_t);
}
double NormalDistribution::median() const
{
    return m_mean;
}