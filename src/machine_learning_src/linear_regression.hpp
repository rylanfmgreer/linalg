// author: rgreer
// nov 19 2022

#ifndef linear_regression_implementation__
#define linear_regression_implementation__

#include "machine_learning.hpp"

class LinearRegression: public SupervisedLearning
{
    public:
    virtual void fit(const Matrix& X, const DoubleVec& y);
    virtual DoubleVec predict(const Matrix& X) const;
    DoubleVec get_coefficients() const;

    private:
    bool is_fit = false;
    DoubleVec beta = DoubleVec(0);
    
}; // end of class

#endif
