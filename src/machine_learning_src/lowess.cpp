#include "lowess.hpp"
#include "../matrix_src/matrix.hpp"
#include "../doublevec_src/doublevec.hpp"

Lowess::Lowess(double p_frac)
:m_frac(p_frac){}

DoubleVec Lowess::calculate_xx(const DoubleVec& p_x) const
{
    return calculate_xy(p_x, p_x);
}

DoubleVec Lowess::calculate_xy(const DoubleVec& p_x, const DoubleVec& p_y) const
{
    DoubleVec xy = p_x * p_y;
    return xy.rolling_sum(window_size, offset_for_sum);
}