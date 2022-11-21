// machine_learning.hpp
// author: rgreer
// pure abstract class for machine learning

#ifndef machine_learning_header_just_abstract_xx
#define machine_learning_header_just_abstract_xx

#include "../doublevec_src/doublevec.hpp"
#include "../matrix_src/matrix.hpp"


class SupervisedRegression
{
public:
    virtual void fit(const Matrix &X, const DoubleVec &y) = 0;
    virtual DoubleVec predict(const Matrix &X) const = 0;
};


class SupervisedClassification
{
public:
    virtual void fit(const Matrix &X, const std::vector<int> &y) = 0;
    virtual std::vector<int> predict(const Matrix &X) const = 0;
};


class UnsupervisedRegression
{
public:
    virtual void fit(const Matrix &X) = 0;
    virtual DoubleVec predict(const Matrix &X) const = 0;
};


class UnsupervisedClassification
{
public:
    virtual void fit(const Matrix &X) = 0;
    virtual std::vector<int> predict(const Matrix &X) const = 0;
};


#endif