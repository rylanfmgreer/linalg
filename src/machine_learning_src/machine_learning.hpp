// machine_learning.hpp
// author: rgreer
// pure abstract class for machine learning

#ifndef machine_learning_header_just_abstract_xx
#define machine_learning_header_just_abstract_xx
#include "../doublevec.hpp"
#include "../matrix.hpp"

class MachineLearning
{
    public:
    virtual void fit(const Matrix& X, const DoubleVec& y) = 0;
    virtual DoubleVec predict(const Matrix& X) const = 0;

};

#endif