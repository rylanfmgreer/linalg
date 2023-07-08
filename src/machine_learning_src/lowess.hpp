#ifndef _lowess_hpp___rg123
#define _lowess_hpp___rg123

#include "machine_learning.hpp"
#include <vector>
#include "../doublevec_src/doublevec.hpp"

class Lowess: public SupervisedRegression
{
    Lowess(double p_frac);

    private:
    double m_frac;
    Matrix m_lowess_params;
    DoubleVec m_initial_x_vals;

    DoubleVec calculate_xx(const DoubleVec& p_x) const;
    DoubleVec calculate_xy(const DoubleVec& p_x, const DoubleVec& p_y) const;
    DoubleVec xx;
    DoubleVec xy;
    int window_size;
    int offset_for_sum;
};

#endif