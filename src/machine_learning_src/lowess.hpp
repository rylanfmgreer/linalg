#ifndef _lowess_hpp___rg123
#define _lowess_hpp___rg123

#include "machine_learning.hpp"
#include <vector>
#include "../doublevec_src/doublevec.hpp"

class Lowess: public SupervisedRegression
{
    Lowess(double p_frac);

    public:
    virtual void fit(const Matrix &X, const DoubleVec &y);
    virtual DoubleVec predict(const Matrix &X) const;

    private:
    double m_frac;
    Matrix m_lowess_params;
    DoubleVec m_initial_x_vals;


    DoubleVec calculate_xx(const DoubleVec& p_x) const;
    DoubleVec calculate_xy(const DoubleVec& p_x, const DoubleVec& p_y) const;
    void calculate_coefficients();

    DoubleVec m_x;
    DoubleVec m_y;
    DoubleVec m_xx;
    DoubleVec m_xy;
    int m_window_size;
    int m_offset_for_sum;
};

#endif