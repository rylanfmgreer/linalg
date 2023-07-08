#include "parameterized_function.hpp"

ParameterizedFunction::ParameterizedFunction() {}

ParameterizedFunction::ParameterizedFunction(two_vec_func p_f)
    : m_f(p_f) {}

ParameterizedFunction::ParameterizedFunction(two_vec_func p_f, DoubleVec m_W)
    : m_f(p_f), m_W(m_W) {}

DoubleVec ParameterizedFunction::operator()(DoubleVec p_x)
{
    return this->x_variable_W_constant(p_x);
}

void ParameterizedFunction::set_function(two_vec_func p_f)
{
    m_f = p_f;
}

void ParameterizedFunction::set_x(DoubleVec p_x)
{
    m_x = p_x;
}

void ParameterizedFunction::set_W(DoubleVec p_W)
{
    m_W = p_W;
}

DoubleVec ParameterizedFunction::x_variable_W_constant(DoubleVec p_x)
{
    return m_f(p_x, m_W);
}

DoubleVec ParameterizedFunction::x_constant_W_variable(DoubleVec p_W)
{
    return m_f(m_x, p_W);
}

DoubleVec ParameterizedFunction::x_variable_W_variable(DoubleVec p_x,
                                                       DoubleVec p_W)
{
    return m_f(p_x, p_W);
}

double ParameterizedFunction::x_variable_W_constant_1d(DoubleVec x_)
{
    DoubleVec z = this->x_variable_W_constant(x_);
    assert(z.size() == 1);
    return z[0];
}

double ParameterizedFunction::x_variable_W_variable_1d(DoubleVec p_x,
                                                       DoubleVec p_W)
{
    DoubleVec z = this->x_variable_W_variable(p_x, p_W);
    assert(z.size() == 1);
    return z[0];
}
