#ifndef _lowess_hpp___rg123
#define _lowess_hpp___rg123

#include "machine_learning.hpp"
#include <vector>
#include "../matrix_src/matrix.hpp"

class Lowess: public SupervisedRegression
{
    Lowess(double p_frac);

    private:
    double m_frac;
    Matrix m_lowess_params;
    DoubleVec m_initial_x_vals;
    

}

#endif