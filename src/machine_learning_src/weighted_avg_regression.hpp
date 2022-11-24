#pragma once
#ifndef weighted_average_regression_nov_22_2022W
#define weighted_average_regression_nov_22_2022W

#include "../doublevec_src/doublevec.hpp"
#include "../matrix_src/matrix.hpp"
#include "../machine_learning_src/machine_learning.hpp"
#include "../utilities_src/parameterized_function.hpp"

/*
    A namespace of functions that one could use for different
    weighted average regressions.
*/
namespace WeightFunc
{
    typedef std::function<DoubleVec(DoubleVec, DoubleVec)> two_vec_func;

    /*
        Given distances and k, return 1 for the k smallest distances
        and 0 for the rest.
    */
    DoubleVec k_nearest_neighbours(DoubleVec distances, DoubleVec k);

    /*
        given distances and w, return exp(-w * d * d)
        for each distance d
    */
    DoubleVec exponential_weighting(DoubleVec distances, DoubleVec w);

    /*
        Dummy function. return 1.
    */
    DoubleVec equal_weights(DoubleVec distances, DoubleVec unused_arg);
};

class WeightedAvgRegression: public SupervisedRegression
{

    public:
    /*
        Initialize with p_dist_to_weight as the weighting function.
    */
    WeightedAvgRegression(WeightFunc::two_vec_func p_dist_to_weight);

    /*
        Fit.
    */
    virtual void fit(const Matrix &X, const DoubleVec &y);

    /*
        Predict.
    */
    virtual DoubleVec predict(const Matrix &X) const;

    /*
        Change the params for your weighting function.
    */
    void set_params(const DoubleVec& params){ m_params = params.deep_copy(); }

    /*
        Return the params for your weighting function.
    */
    DoubleVec get_params(){ return m_params.deep_copy(); }

    private:
    /*
        For prediction.
        Given a single observation x (x being a row)
        of a larger matrix X) calculate all distances between x and
        the rows of X_train.
    */
    DoubleVec calculate_all_distances(const DoubleVec& observation) const;
    WeightFunc::two_vec_func m_distance_to_weight;
    DoubleVec m_params;
    Matrix X_train;
    DoubleVec y_train;
    WeightedAvgRegression();
}; // end of weighted avg regression class

#endif
