#include "linear_regression.hpp"
using namespace std;
void LinearRegression::fit(const Matrix& X, const DoubleVec& y)
{
    Matrix XTX = X.transpose().matmul(X);
    DoubleVec XTy = X.transpose() * y;
    this->m_beta = XTX.invert() * XTy;
    m_is_fit = true;
}

DoubleVec LinearRegression::predict(const Matrix& X) const
{
    assert(this->m_is_fit);
    return X * m_beta;
}

DoubleVec LinearRegression::get_coefficients() const
{
    assert(this->m_is_fit);
    return m_beta.deep_copy();
}