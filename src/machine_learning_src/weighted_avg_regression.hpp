#pragma once
#ifndef weighted_average_regression_nov_22_2022W
#define weighted_average_regression_nov_22_2022W

#include "../doublevec_src/doublevec.hpp"
#include "../matrix_src/matrix.hpp"
#include "../machine_learning_src/machine_learning.hpp"
#include "../utilities_src/parameterized_function.hpp"

namespace WeightFunc
{
    typedef std::function<DoubleVec(DoubleVec, DoubleVec)> two_vec_func;
    DoubleVec k_nearest_neighbours(DoubleVec distances, DoubleVec k);
    DoubleVec exponential_weighting(DoubleVec distances, DoubleVec w);
    DoubleVec equal_weights(DoubleVec distances, DoubleVec unused_arg);
};

class WeightedAvgRegression: public SupervisedRegression
{

    public:
    WeightedAvgRegression(WeightFunc::two_vec_func p_dist_to_weight);
    virtual void fit(const Matrix &X, const DoubleVec &y);
    virtual DoubleVec predict(const Matrix &X) const;
    void set_params(const DoubleVec& params){ m_params = params.deep_copy(); }
    DoubleVec get_params(){ return m_params.deep_copy(); }

    private:
    WeightedAvgRegression();
    WeightFunc::two_vec_func m_distance_to_weight;
    DoubleVec m_params;
    Matrix X_train;
    DoubleVec y_train;

    // called in predict
    DoubleVec calculate_all_distances(const DoubleVec& observation) const;

}; // end of weighted avg regression class

#endif