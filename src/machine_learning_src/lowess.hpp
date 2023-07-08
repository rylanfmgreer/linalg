#ifndef _lowess_hpp___rg123
#define _lowess_hpp___rg123

#include "machine_learning.hpp"
#include <vector>
#include "../doublevec_src/doublevec.hpp"

class Lowess: public SupervisedRegression
{
    Lowess(double p_frac);

    public:
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

    // helpers for predicting
    Matrix calculate_raw_linear_estimates(const Matrix& p_X) const;
    Matrix calculate_weights_for_estimates(const Matrix& p_X) const;
    DoubleVec calculate_full_predictions(
        const Matrix& p_raw_est, const Matrix& p_weights) const;

    DoubleVec m_x;
    DoubleVec m_y;
    DoubleVec m_x_mean;
    DoubleVec m_y_mean;
    DoubleVec m_x_squared;
    DoubleVec m_x_times_y;
    DoubleVec m_alphas;
    DoubleVec m_betas;
    int m_window_size;
    int m_offset_for_sum;
};

#endif