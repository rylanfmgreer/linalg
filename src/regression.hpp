// regression.hpp
// author: rgreer

#ifndef __regression_header_128___
#define __regression_header_128___

#include "doublevec.hpp"
#include "matrix.hpp"
#include "parameterized_function.hpp"

class LinearRegression
{
    public:
    LinearRegression();
    LinearRegression(bool include_intercept);
    void fit(Matrix x, DoubleVec y);
    void fit(Matrix x, Matrix y);
    DoubleVec predict(DoubleVec x);

    private:
    bool intercept_included;
    bool has_been_fit;
    DoubleVec beta;
    
}; // end of class

#endif