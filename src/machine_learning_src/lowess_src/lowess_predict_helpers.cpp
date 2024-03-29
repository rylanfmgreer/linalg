#include "../lowess.hpp"
#include "../../doublevec_src/doublevec.hpp"
#include "../../matrix_src/matrix.hpp"
#include "../kernel_src/kernel.hpp"

Matrix Lowess::calculate_raw_linear_estimates(const Matrix& p_X) const
{
    /*
    p_X: just use the first column
    */
    DoubleVec x = p_X.col(0);
    std::vector<DoubleVec> matrix_cols;
    for( int c(0); c < m_y.size(); ++c)
    {
        DoubleVec estimates =(x[c] * m_betas) + m_alphas;
        matrix_cols.push_back(estimates);
    }
    Matrix full_matrix(matrix_cols);
     return full_matrix;
}

Matrix Lowess::calculate_weights_for_estimates(const Matrix& p_X) const
{
    return m_kernel.calculate_weights(p_X.col(0));
}

DoubleVec Lowess::calculate_full_predictions(
    const Matrix& p_raw_est, const Matrix& p_weights) const
{    
    DoubleVec predictions(p_raw_est.nrow());
    for( int i(0); i < predictions.size(); ++i)
        predictions[i] = p_raw_est.col(i) * p_weights.col(i);
    return predictions;
}