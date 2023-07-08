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
    calculate_intermediate_values_for_params();
    calculate_betas_for_fit();
    calculate_alphas_for_fit();
}

void Lowess::calculate_intermediate_values_for_params()
{
    calculate_basic_x_y_means();
    calculate_cross_products();
    calculate_means_of_cross_products();
    calculate_squares_of_means();
    calculate_covariances();
    
}
void Lowess::calculate_basic_x_y_means()
{
    m_x_mean = calculate_rolling_mean_for_fit(m_x);
    m_y_mean = calculate_rolling_mean_for_fit(m_y);
}

void Lowess::calculate_cross_products()
{
    m_x_x = m_x.elementwise_multiply(m_x);
    m_x_y = m_x.elementwise_multiply(m_y);
}

void Lowess::calculate_means_of_cross_products()
{
    m_x_x_mean = calculate_rolling_mean_for_fit(m_x_x);
    m_x_y_mean = calculate_rolling_mean_for_fit(m_x_y);
}
void Lowess::calculate_squares_of_means()
{
    m_x_mean_x_mean = m_x_mean.elementwise_multiply(m_x_mean);
    m_x_mean_y_mean = m_x_mean.elementwise_multiply(m_y_mean);
}

void Lowess::calculate_covariances()
{
    m_cov_x_x = calculate_variance(m_x_x_mean, m_x_mean_x_mean);
    m_cov_x_y = calculate_variance(m_x_y_mean, m_x_mean_y_mean);
}

DoubleVec Lowess::calculate_variance(
    const DoubleVec& p_mean_sq_vec, const DoubleVec& p_mean_vec_sq) const
{
    return p_mean_sq_vec - p_mean_vec_sq ;
}

void Lowess::calculate_alphas_for_fit()
{
    m_alphas = m_y_mean - m_betas.elementwise_multiply(m_x_mean);
}

void Lowess::calculate_betas_for_fit()
{
    m_betas = m_cov_x_y / m_cov_x_x;    
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
    DoubleVec xy = p_x.elementwise_multiply(p_y);
    return xy.rolling_sum(m_window_size, m_offset_for_sum);
}

void Lowess::save_x_and_y_for_fit(const Matrix &p_X, const DoubleVec &p_y)
{
    m_x = p_X.col(0);
    m_y = p_y;
}

