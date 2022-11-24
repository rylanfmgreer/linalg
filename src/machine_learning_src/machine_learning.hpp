// machine_learning.hpp
// author: rgreer
// pure abstract class for machine learning

#pragma once
#ifndef machine_learning_header_just_abstract_xx
#define machine_learning_header_just_abstract_xx

#include "../doublevec_src/doublevec.hpp"
#include "../matrix_src/matrix.hpp"

/*
    Pure abstract class for supervised regression.
*/
class SupervisedRegression
{
public:
    /*
        Fit the model.
    */
    virtual void fit(const Matrix &X, const DoubleVec &y) = 0;

    /*
        Predict on the fit model.
    */
    virtual DoubleVec predict(const Matrix &X) const = 0;
};

/*
    Pure abstract class for supervised classification.
*/
class SupervisedClassification
{
public:
    /*
        Fit the model.
    */
    virtual void fit(const Matrix &X, const std::vector<int> &y) = 0;

    /*
        Predict on the fit model.
    */
    virtual std::vector<int> predict(const Matrix &X) const = 0;
};

/*
    Pure abstract class for unsupervised regression.
*/
class UnsupervisedRegression
{
public:
    /*
        Fit the model.
    */
    virtual void fit(const Matrix &X) = 0;

    /*
        Predict on the fit model.
    */
    virtual DoubleVec predict(const Matrix &X) const = 0;
};

/*
    Pure abstract class for unsupervised classification.
*/
class UnsupervisedClassification
{
public:
    /*
        Fit the model.
    */
    virtual void fit(const Matrix &X) = 0;
    
    /*
        Predict on the fit model.
    */
    virtual std::vector<int> predict(const Matrix &X) const = 0;
};


#endif