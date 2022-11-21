#include "../doublevec_src/doublevec.hpp"
#include "../matrix_src/matrix.hpp"
#include "../machine_learning_src/machine_learning.hpp"
#include "../utilities_src/parameterized_function.hpp"

namespace WeightFunc
{
    typedef std::function<DoubleVec(DoubleVec, DoubleVec)> two_vec_func;
    DoubleVec k_nearest_neighbours(DoubleVec distances, DoubleVec k);
};

class WeightedAvgRegression: public SupervisedRegression
{

    public:
    WeightedAvgRegression(std::function< DoubleVec(DoubleVec) > p_dist_to_weight);
    virtual void fit(const Matrix &X, const DoubleVec &y);
    virtual DoubleVec predict(const Matrix &X) const;

    private:
    WeightedAvgRegression();
    std::function< DoubleVec(DoubleVec) > m_distance_to_weight;
    DoubleVec m_function_params;
    Matrix X_train;
    DoubleVec y_train;

    // called in predict
    DoubleVec calculate_all_distances(const DoubleVec& observation) const;

}; // end of weighted avg regression class