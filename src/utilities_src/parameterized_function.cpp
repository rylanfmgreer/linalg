#include "parameterized_function.hpp"

ParameterizedFunction::ParameterizedFunction() {}

ParameterizedFunction::ParameterizedFunction(two_vec_func f)
    : m_f(f) {}

ParameterizedFunction::ParameterizedFunction(two_vec_func f, DoubleVec W)
    : m_f(f), m_W(W) {}

DoubleVec ParameterizedFunction::operator()(DoubleVec x_)
{
    return this->x_variable_W_constant(x_);
}

void ParameterizedFunction::set_function(two_vec_func f_)
{
    m_f = f_;
}

void ParameterizedFunction::set_x(DoubleVec x_)
{
    this->m_x = x_;
}

void ParameterizedFunction::set_W(DoubleVec W_)
{
    this->m_W = W_;
}

DoubleVec ParameterizedFunction::x_variable_W_constant(DoubleVec x_)
{
    return m_f(x_, m_W);
}

DoubleVec ParameterizedFunction::x_constant_W_variable(DoubleVec W_)
{
    return m_f(m_x, W_);
}

DoubleVec ParameterizedFunction::x_variable_W_variable(DoubleVec x_,
                                                       DoubleVec W_)
{
    return m_f(x_, W_);
}

double ParameterizedFunction::x_variable_W_constant_1d(DoubleVec x_)
{
    DoubleVec z = x_variable_W_constant(x_);
    assert(z.size() == 1);
    return z[0];
}

double ParameterizedFunction::x_variable_W_variable_1d(DoubleVec x_,
                                                       DoubleVec W_)
{
    DoubleVec z = x_variable_W_variable(x_, W_);
    assert(z.size() == 1);
    return z[0];
}
