// author: rgreer
#pragma once
#ifndef k_means_hpp_____
#define k_means_hpp_____

#include "machine_learning.hpp"

/*
    Some utilities that will be used for KMeans.
*/
namespace KMeans_Utils
{
    /*
        A POD struct so that we can have one function both
        return the means and the cluster labels. This if
        for greater efficiency.
    */
    struct ResultOfRound
    {
    public:
        Matrix cluster_means;
        std::vector<int> cluster_labels;
    };

}; // end of namespace

/*
    A KMeans "classifier."
    TODO: reimplement using classification, NOT regression.
*/
class KMeans : public UnsupervisedRegression
{
public:
    /*
        Initialize. 
        fit n_means clusters.
        perform n_rounds fitting rounds, each with n_iterations_per_round
        iterations per round.
    */
    KMeans(int n_means, int n_rounds, int n_iterations_per_round);

    /*
        Fit on a matrix.
    */
    virtual void fit(const Matrix &X);

    /*
        Predict cluster labels on a matrix.
    */
    virtual DoubleVec predict(const Matrix &X) const;

private:
    Matrix m_fitted_cluster_means;
    int m_n_means;
    int m_n_rounds;
    int m_n_it_per_round;

    /*
        For the fitting algorithm -- complete one round
        and return the labels and the cluster means
        as a ResultOfRound
    */
    KMeans_Utils::ResultOfRound complete_one_fitting_round(
        const Matrix &X) const;

    /*
        Calculate the "score", or average squared distance from cluster mean.
    */
    double score_from_one_fitting_round(const Matrix &X,
                                        const Matrix &cluster_means,
                                        const std::vector<int> cluster_labels) const;

    /*
        Initialize the clusters.
    */
    std::vector<int> initialize_round_clusters(int n_observations) const;

    /*
        Deprecated. One way of initializing means...
    */
    Matrix initialize_random_means(const Matrix &X) const;

    /*
        Given X and labels, calculate the cluster means.
    */
    Matrix calculate_means_by_cluster(const Matrix &X,
                                      std::vector<int> cluster_labels) const;

    /*
        Find which cluster label is actually closest to each observation
        given the current cluster means.
        Calls find_closest_mean_to_observation for each observation.
    */
    std::vector<int> reassign_clusters_by_new_cluster_mean(
        const Matrix &X, const Matrix &cluster_means) const;

    /*
        Find which mean is closest.
    */
    int find_closest_mean_to_observation(const DoubleVec &observation,
                                         const Matrix &cluster_means) const;
    /*
        Algorithm currently in use -- start off your cluster means
        by averaging out real data
    */
    Matrix initialize_random_means_from_data(const Matrix &X) const;

}; // end of class

#endif