#ifndef univariate_dist_rg___
#define univariate_dist_rg___

class UnivariateDistribution
{
    // an abstract class meant to represent a probability distribution

    public:
    virtual double cdf(double p_x) const = 0;
    virtual double pdf(double p_x) const = 0;
    virtual double expectation() const = 0;
    virtual double variance() const = 0;

    protected:
    double m_lower_bound;
    double m_upper_bound;

    private:
};


#endif