#include "lowess.hpp"
#include "../matrix_src/matrix.hpp"
#include "../doublevec_src/doublevec.hpp"

Lowess::Lowess(double p_frac)
:m_frac(p_frac){}

DoubleVec Lowess::predict(const Matrix& p_X) const
{
    DoubleVec ret;
    return ret;
}
