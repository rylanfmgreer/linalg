// author: rgreer
// nov 19 2022

#pragma once
#ifndef linear_regression_implementation__
#define linear_regression_implementation__

#include "machine_learning.hpp"

class LinearRegression: public SupervisedRegression
{
    public:
    virtual void fit(const Matrix& X, const DoubleVec& y);
    virtual DoubleVec predict(const Matrix& X) const;
    DoubleVec get_coefficients() const;

    protected:
    bool m_is_fit = false;
    DoubleVec m_beta = DoubleVec(0);
    
}; // end of class

#endif
