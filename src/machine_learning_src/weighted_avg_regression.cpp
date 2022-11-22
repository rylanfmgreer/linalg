#include "weighted_avg_regression.hpp"
#include "../utilities_src/utility_functions.hpp"

// for convenience, typedef the longer names.

WeightedAvgRegression::WeightedAvgRegression(
    WeightFunc::two_vec_func p_dist_to_weight)
: m_distance_to_weight(p_dist_to_weight)
{
    DoubleVec params(1); // dummy initialization
    m_params = params;
}

void WeightedAvgRegression::fit(const Matrix& X, const DoubleVec& y)
{
    X_train = X.deep_copy(); 
    y_train = y.deep_copy();
}

DoubleVec WeightedAvgRegression::predict(const Matrix& X_test) const
{
    // todo: rewrite everything to be more efficient
    int n_observations = X_test.nrow();
    DoubleVec predictions(n_observations);

    for( int i(0); i < n_observations; ++i )
    {
        DoubleVec observation = X_test.row(i);
        DoubleVec obs_distance = calculate_all_distances(observation);
        DoubleVec weights = m_distance_to_weight(obs_distance, m_params);
        predictions[i] = weights * obs_distance;
    }
    return predictions;
}

DoubleVec WeightedAvgRegression::calculate_all_distances(const DoubleVec& observation) const
{
    int n_training_obs = X_train.nrow();
    DoubleVec distances(n_training_obs);
    for( int i(0); i < n_training_obs; ++i )
        distances[i] = (X_train.row(i) - observation).norm();
    return distances;    
}

namespace WeightFunc
{
    DoubleVec k_nearest_neighbours(DoubleVec distances, DoubleVec k)
    {
        assert( k.size() == 1 );
        unsigned int n_neighbours = util::crude_double_to_int(k[0]);
        DoubleVec sorted_distances = distances.sort();
        double kth_distance = sorted_distances[n_neighbours];
        std::vector<double> new_data(distances.size());
        std::transform(new_data.begin(), new_data.end(),
                       new_data.begin(), [kth_distance]( double x )
                       {
                        if(x > kth_distance)
                            return 0.;
                        return 1.;
                       });
        DoubleVec ret_dv(new_data);
        return ret_dv;
    }

    DoubleVec exponential_weighting(DoubleVec distances, DoubleVec w)
    {
        assert( w.size() == 1 );
        std::vector<double> new_data(distances.size());
        double d_w = w[0];
        std::transform(distances.data.begin(), distances.data.end(),
                       new_data.begin(), [d_w]( double x )
                       {
                        return exp( -d_w * x * x );
                       });
        DoubleVec new_dv(new_data);
        return new_dv;
    }

    DoubleVec equal_weights(DoubleVec distances, DoubleVec unused_arg)
    {
        DoubleVec ones( distances.size(), 1.);
        return ones;
    }

}