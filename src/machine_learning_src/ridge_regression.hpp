#pragma once
#ifndef __ridge_regression_rg_nov_24_2022__
#define __ridge_regression_rg_nov_24_2022__
#include "linear_regression.hpp"

class RidgeRegression: public LinearRegression
{
    public:
    RidgeRegression(double p_lambda = 0);
    virtual void fit(const Matrix& X, const DoubleVec& y);
    void set_lambda(double p_lambda);
    double get_lambda() const;
    
    protected:
    double m_lambda;
    DoubleVec m_beta;
    
};

#endif