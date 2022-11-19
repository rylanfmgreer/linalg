#include "linear_regression.hpp"
using namespace std;
void LinearRegression::fit(const Matrix& X, const DoubleVec& y)
{
    Matrix XTX = X.transpose().matmul(X);
    DoubleVec XTy = X.transpose() * y;
    this->beta = XTX.invert() * XTy;
    is_fit = true;
}

DoubleVec LinearRegression::predict(const Matrix& X) const
{
    assert(this->is_fit);
    return X * beta;
}

DoubleVec LinearRegression::get_coefficients() const
{
    assert(this->is_fit);
    return beta.deep_copy();
}