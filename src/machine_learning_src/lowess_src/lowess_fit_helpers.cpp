#include "../lowess.hpp"

DoubleVec Lowess::calculate_xx_for_fit(const DoubleVec& p_x) const
{
    return calculate_xy_for_fit(p_x, p_x);
}

DoubleVec Lowess::calculate_rolling_mean_for_fit(const DoubleVec& p_vec) const
{
    return p_vec.rolling_mean(m_window_size, m_offset_for_sum);
}
void Lowess::calculate_coefficients_for_fit()
{
    m_x_mean = calculate_rolling_mean_for_fit(m_x);
    m_y_mean = calculate_rolling_mean_for_fit(m_y);
    m_x_squared = calculate_xx_for_fit(m_x);
    m_x_times_y = calculate_xy_for_fit(m_x, m_y);
    calculate_betas_for_fit();
    calculate_alphas_for_fit();
}

void Lowess::calculate_alphas_for_fit()
{
    m_alphas = m_y_mean - m_betas * m_x_mean;
}

void Lowess::calculate_betas_for_fit()
{
    m_betas = m_x_times_y / m_x_squared;    

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

