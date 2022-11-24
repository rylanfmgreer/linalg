#include "ridge_regression.hpp"


RidgeRegression::RidgeRegression(double p_lambda)
:m_lambda(p_lambda){}

void RidgeRegression::fit(const Matrix& X, const DoubleVec& y)
{
    int n = X.ncol();
    Matrix lambda_I = Matrix(n) * m_lambda;
    Matrix XTXpLI = (X.T() * X + lambda_I);
    Matrix XTy = X.T() * y;
    m_beta = XTXpLI.invert() * XTy;
}

void RidgeRegression::set_lambda(double p_lambda)
{
    m_lambda = p_lambda;
}

double RidgeRegression::get_lambda() const
{
    return m_lambda;
}