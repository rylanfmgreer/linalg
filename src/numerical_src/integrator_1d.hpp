#include <functional>
#include <iostream>

namespace Int1D
{
    typedef std::function<double(double)> func;
};

class Integrator_1D
{
    public:
    Integrator_1D(Int1D::func& f, double p_lb, double p_ub, double p_tolerance=1e-8);
    virtual double integrate() = 0;


    private:

    int m_step;
    Int1D::func& f;
    double m_ub;
    double m_lb;
    double m_tolerance;
};