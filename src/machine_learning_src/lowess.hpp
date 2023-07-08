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


    DoubleVec calculate_xx_for_fit(const DoubleVec& p_x) const;
    DoubleVec calculate_xy_for_fit(const DoubleVec& p_x, const DoubleVec& p_y) const;
    void save_x_and_y_for_fit(const Matrix& p_X, const DoubleVec& p_y);
    void calculate_coefficients_for_fit();

    DoubleVec calculate_predictions(const Matrix& p_X);
    DoubleVec calculate_weights_on_predictions(const Matrix& p_X);

    DoubleVec m_x;
    DoubleVec m_y;
    DoubleVec m_xx;
    DoubleVec m_xy;
    int m_window_size;
    int m_offset_for_sum;
};

#endif