#include "integrator_1d.hpp"
Integrator_1D::Integrator_1D(
    Int1D::func& f, double p_lb, double p_ub,
    double p_tolerance=1e-8)
    :m_f(p_f), m_lb(p_lb), m_ub(p_ub), m_tolerance(p_tolerance), m_step(0){}