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
    return xy.rolling_sum(m_window_size, m_offset_for_sum);
}

void Lowess::save_x_and_y(const Matrix &p_X, const DoubleVec &p_y)
{
    m_x = p_X.col(0);
    m_y = p_y;
}

void Lowess::fit(const Matrix &p_X, const DoubleVec &p_y)
{
    save_x_and_y(p_X, p_y);
    calculate_coefficients()

}

void Lowess::calculate_coefficients()
{
    m_xx = calculate_xx(m_x);
    m_xy = calculate_xy(m_x, m_y);

}