#pragma once
#ifndef __ridge_regression_rg_nov_24_2022__
#define __ridge_regression_rg_nov_24_2022__
#include "linear_regression.hpp"

class RidgeRegression: public LinearRegression
{
    public:

    /*
        Initialize the ridge regression.
    */
    RidgeRegression(double p_lambda = 0);

    /*
        Fit the regression.
    */
    virtual void fit(const Matrix& X, const DoubleVec& y);

    /*
        Set lambda
    */
    void set_lambda(double p_lambda);

    /*
        Get lambda
    */
    double get_lambda() const;
    
    protected:
    double m_lambda;
    
};

#endif