// machine_learning.hpp
// author: rgreer
// pure abstract class for machine learning

#ifndef machine_learning_header_just_abstract_xx
#define machine_learning_header_just_abstract_xx

#include "../doublevec_src/doublevec.hpp"
#include "../matrix_src/matrix.hpp"

class SupervisedLearning
{
    public:
    virtual void fit(const Matrix& X, const DoubleVec& y) = 0;
    virtual DoubleVec predict(const Matrix& X) const = 0;

};

class UnsupervisedLearning
{
    public:
    virtual void fit(const Matrix& X) = 0;
    virtual DoubleVec predict(const Matrix& X) const = 0;

};


#endif