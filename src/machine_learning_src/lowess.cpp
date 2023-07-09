#include "lowess.hpp"
#include "../matrix_src/matrix.hpp"
#include "../doublevec_src/doublevec.hpp"

Lowess::Lowess(double p_frac)
:m_frac(p_frac){}

void Lowess::fit(const Matrix &p_X, const DoubleVec &p_y)
{
    save_x_and_y_for_fit(p_X, p_y);
    m_kernel.set_fitting_weights(m_x);
    calculate_window_size();
    calculate_offset_size();
    calculate_coefficients_for_fit();
}

DoubleVec Lowess::predict(const Matrix& p_X) const
{
    Matrix raw_estimates = calculate_raw_linear_estimates(p_X);
    Matrix weights = calculate_weights_for_estimates(p_X);
    DoubleVec predictions = calculate_full_predictions(
        raw_estimates, weights);
    return predictions;
}