#include "kernel.hpp"
#include <cmath>
void Kernel::set_fitting_weights(const DoubleVec& p_w)
{
    m_fitted_weights = p_w;
}

Matrix Kernel::initialize_distance_matrix(const DoubleVec& p_new_x) const
{
    int nrow = p_new_x.size();
    int ncol = m_fitted_weights.size();
    Matrix distances(nrow, ncol);
    return distances;
}

Matrix Kernel::calculate_distances(const DoubleVec& p_new_x) const
{
    Matrix distances = initialize_distance_matrix(p_new_x);

    for (int row_idx(0); row_idx < distances.nrow(); ++row_idx)
    {
        double evaluation_point = p_new_x.get(row_idx);
    
        for (int col_idx(0); col_idx < distances.ncol(); ++col_idx)
        {
            double base_point = m_fitted_weights.get(col_idx);
            double dist = (evaluation_point - base_point);
            dist = dist * dist;
            distances(row_idx, col_idx) = dist;
        }
    }
    return distances;
}

Matrix Kernel::apply_weighting_function(Matrix& p_distances) const
{
    double denom = m_denominator;
    return p_distances.apply(
        [denom](double x){ 
            double y = - (x * x / denom);
            return exp(y);
            });
}

Matrix Kernel::calculate_weights(const DoubleVec& p_new_x) const
{
    Matrix W = calculate_distances(p_new_x);
    W = apply_weighting_function(W);
    return W;
}