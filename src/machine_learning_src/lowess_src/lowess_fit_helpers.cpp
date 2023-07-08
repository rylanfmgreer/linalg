#include "../lowess.hpp"

DoubleVec Lowess::calculate_xx_for_fit(const DoubleVec& p_x) const
{
    return calculate_xy_for_fit(p_x, p_x);
}

void Lowess::calculate_coefficients_for_fit()
{
    m_xx = calculate_xx_for_fit(m_x);
    m_xy = calculate_xy_for_fit(m_x, m_y);

}

void Lowess::calculate_window_size()
{
    m_window_size = int(m_x.size() * m_frac);
}

void Lowess::calculate_offset_size()
{
    m_offset_for_sum = m_window_size / 2;
}

DoubleVec Lowess::calculate_xy_for_fit(const DoubleVec& p_x, const DoubleVec& p_y) const
{
    DoubleVec xy = p_x * p_y;
    return xy.rolling_sum(m_window_size, m_offset_for_sum);
}

void Lowess::save_x_and_y_for_fit(const Matrix &p_X, const DoubleVec &p_y)
{
    m_x = p_X.col(0);
    m_y = p_y;
}

void Lowess::fit(const Matrix &p_X, const DoubleVec &p_y)
{
    save_x_and_y_for_fit(p_X, p_y);
    calculate_coefficients_for_fit();
}