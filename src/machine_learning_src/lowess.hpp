#ifndef _lowess_hpp___rg123
#define _lowess_hpp___rg123

#include "machine_learning.hpp"
#include <vector>
#include "../doublevec_src/doublevec.hpp"

class Lowess: public SupervisedRegression
{

    public:
    Lowess(double p_frac=0.3);
    virtual void fit(const Matrix &p_X, const DoubleVec &p_y);
    virtual DoubleVec predict(const Matrix &p_X) const;

    private:
    double m_frac;
    Matrix m_lowess_params;
    DoubleVec m_initial_x_vals;

    // helpers for fitting
    DoubleVec calculate_xx_for_fit(const DoubleVec& p_x) const;
    DoubleVec calculate_xy_for_fit(const DoubleVec& p_x, const DoubleVec& p_y) const;
    DoubleVec calculate_rolling_mean_for_fit(const DoubleVec& p_vec) const;
    void calculate_window_size();
    void calculate_offset_size();
    void save_x_and_y_for_fit(const Matrix& p_X, const DoubleVec& p_y);
    void calculate_coefficients_for_fit();
    void calculate_alphas_for_fit();
    void calculate_betas_for_fit();
    void calculate_basic_x_y_means();
    void calculate_cross_products();
    void calculate_squares_of_means();
    void calculate_means_of_cross_products();
    void calculate_covariances();
    void calculate_intermediate_values_for_params();

    DoubleVec calculate_variance(
        const DoubleVec& p_mean_sq_vec, const DoubleVec& p_mean_vec_sq) const;

    // helpers for predicting
    Matrix calculate_raw_linear_estimates(const Matrix& p_X) const;
    Matrix calculate_weights_for_estimates(const Matrix& p_X) const;
    DoubleVec calculate_full_predictions(
        const Matrix& p_raw_est, const Matrix& p_weights) const;

    DoubleVec m_x;
    DoubleVec m_y;

    DoubleVec m_x_mean;
    DoubleVec m_y_mean;

    DoubleVec m_x_x_mean;
    DoubleVec m_x_y_mean;

    DoubleVec m_x_mean_x_mean;
    DoubleVec m_x_mean_y_mean;

    DoubleVec m_x_x;
    DoubleVec m_x_y;

    DoubleVec m_cov_x_x;
    DoubleVec m_cov_x_y;

    DoubleVec m_alphas;
    DoubleVec m_betas;

    int m_window_size;
    int m_offset_for_sum;
};

#endif