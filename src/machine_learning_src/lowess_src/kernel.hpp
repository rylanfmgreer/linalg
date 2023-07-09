#ifndef _lowess_kernel__9juil2023
#define _lowess_kernel__9juil2023

#include "../lowess.hpp"
#include "../../matrix_src/matrix.hpp"

class Kernel: public ParameterizedFunction
{
    public:
    Kernel(double p_denom=0.3): m_denominator(p_denom){}
    void set_fitting_weights(const DoubleVec& p_fitted_weights);
    Matrix calculate_weights(const DoubleVec& p_new_x) const;

    private:
    double m_denominator;
    std::function<double (double, double)> m_1d_kernel;
    DoubleVec m_fitted_weights;
    Matrix initialize_distance_matrix(const DoubleVec& p_new_x) const;
    Matrix calculate_distances(const DoubleVec& p_new_x) const;
    Matrix apply_weighting_function(Matrix& p_distances) const;
    
};

#endif