#include "parameterized_function.hpp"

ParameterizedFunction::ParameterizedFunction() {}

ParameterizedFunction::ParameterizedFunction(two_vec_func f)
    : f(f) {}

ParameterizedFunction::ParameterizedFunction(two_vec_func f, DoubleVec W)
    : f(f), W(W) {}

DoubleVec ParameterizedFunction::operator()(DoubleVec x_)
{
    return this->x_variable_W_constant(x_);
}

void ParameterizedFunction::set_function(two_vec_func f_)
{
    this->f = f_;
}

void ParameterizedFunction::set_x(DoubleVec x_)
{
    this->x = x_;
}

void ParameterizedFunction::set_W(DoubleVec W_)
{
    this->W = W_;
}

DoubleVec ParameterizedFunction::x_variable_W_constant(DoubleVec x_)
{
    return f(x_, W);
}

DoubleVec ParameterizedFunction::x_constant_W_variable(DoubleVec W_)
{
    return f(x, W_);
}

DoubleVec ParameterizedFunction::x_variable_W_variable(DoubleVec x_,
                                                       DoubleVec W_)
{
    return f(x_, W_);
}

double ParameterizedFunction::x_variable_W_constant_1d(DoubleVec x_)
{
    DoubleVec z = this->x_variable_W_constant(x_);
    assert(z.size() == 1);
    return z[0];
}

double ParameterizedFunction::x_variable_W_variable_1d(DoubleVec x_,
                                                       DoubleVec W_)
{
    DoubleVec z = this->x_variable_W_variable(x_, W_);
    assert(z.size() == 1);
    return z[0];
}
