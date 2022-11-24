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
        General function f(x, W) -> y
        x in R^m, W in R^n, y in R^p

        In general, we will think of the parameters W as the second input to
        f, and the argument x as the first input.r

    */
public:
    ParameterizedFunction();
    ParameterizedFunction(two_vec_func f);
    ParameterizedFunction(two_vec_func f, DoubleVec params);

    DoubleVec operator()(DoubleVec x);
    
    void set_x(DoubleVec x);
    void set_W(DoubleVec W);
    void set_function(two_vec_func f);

    DoubleVec x_variable_W_constant(DoubleVec x);
    DoubleVec x_constant_W_variable(DoubleVec W);
    DoubleVec x_variable_W_variable(DoubleVec x, DoubleVec W);

    // potential 1d functions
    double x_variable_W_constant_1d(DoubleVec x);
    double x_variable_W_variable_1d(DoubleVec x, DoubleVec W);

private:
    two_vec_func f;
    DoubleVec W;
    DoubleVec x;

}; // of ParameterizedFunction class

#endif