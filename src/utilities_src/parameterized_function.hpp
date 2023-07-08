// author: rgreer
#pragma once
#ifndef parameterized_function_ohgoodlordx__
#define parameterized_function_ohgoodlordx__

#include "../doublevec_src/doublevec.hpp"

// type signature is too long...!
typedef std::function<DoubleVec(DoubleVec, DoubleVec)> two_vec_func;

class ParameterizedFunction
{
    /*
        General function p_f(p_x, p_W) -> y
        p_x in R^m, p_W in R^n, y in R^p

        In general, we will think of the parameters p_W as the second input to
        p_f, and the argument p_x as the first input.r

    */
public:
    ParameterizedFunction();
    ParameterizedFunction(two_vec_func p_f);
    ParameterizedFunction(two_vec_func p_f, DoubleVec p_params);

    DoubleVec operator()(DoubleVec p_x);
    
    void set_x(DoubleVec p_x);
    void set_W(DoubleVec p_W);
    void set_function(two_vec_func p_f);

    DoubleVec x_variable_W_constant(DoubleVec p_x);
    DoubleVec x_constant_W_variable(DoubleVec p_W);
    DoubleVec x_variable_W_variable(DoubleVec p_x, DoubleVec p_W);

    // potential 1d functions
    double x_variable_W_constant_1d(DoubleVec p_x);
    double x_variable_W_variable_1d(DoubleVec p_x, DoubleVec p_W);

private:
    two_vec_func m_f;
    DoubleVec m_W;
    DoubleVec m_x;

}; // of ParameterizedFunction class

#endif