//author: rgreer
#include <float.h>
#include "k_means.hpp"
#include "../utility_functions.hpp"

KMeans::KMeans(int n_means, int n_rounds, int n_iterations_per_round)
:m_n_means(n_means), m_n_rounds(n_rounds),
m_n_it_per_round(n_iterations_per_round)
{    
}

std::vector<int> KMeans::initialize_round_clusters(const Matrix& X) const
{
    int n_objects_to_initialize = X.nrow();
    int n_means = m_n_means;
    std::vector<int> clusters(n_objects_to_initialize);
    std::transform(clusters.begin(),
                   clusters.end(),
                   clusters.begin(),
                   [n_means](int x){ return util::rand_with_max_n(n_means); }
    );
    return clusters;
}

Matrix KMeans::calculate_means_by_cluster(
    const Matrix& X, std::vector<int> cluster_labels) const
{
    std::vector<Matrix> matrices(m_n_means);
    int cluster_label;

    // build the matrices associated with each cluster
    for( int i(0); i < cluster_labels.size(); ++i)
    {
        cluster_label = cluster_labels[i];
        matrices[cluster_label].append_row(X.row(i));
    }

    // calculate the mean by column for each.
    Matrix potential_cluster_means;
    for( int i(0); i < m_n_means; ++i)
    {
        potential_cluster_means.append_col(
            matrices[i].mean_by_col());
    }
    return potential_cluster_means;

}

int KMeans::find_closest_mean_to_observation(
            const DoubleVec& observation,
            const Matrix& cluster_means) const
{
    double minimum_distance = DBL_MAX;
    int closest_cluster = -1;
    DoubleVec cluster_to_check;
    double distance_to_check;
    for( int i(0); i < m_n_means; ++i)
    {
        cluster_to_check = cluster_means.col(i);
        distance_to_check = (cluster_to_check - observation).sq_norm();
        if( distance_to_check < minimum_distance)
            closest_cluster = i;
    }
    return closest_cluster;

}

std::vector<int> KMeans::reassign_clusters_by_new_cluster_mean(
        const Matrix& X, const Matrix& cluster_means) const
{
    int n_observations = X.nrow();
    std::vector<int> new_clusters(n_observations);
    DoubleVec observation_to_check;
    for(int i(0); i < n_observations; ++i)
    {
        observation_to_check = X.row(i);
        new_clusters[i] = find_closest_mean_to_observation(
            observation_to_check, X);
    }
    return new_clusters;
}

KMeans_Utils::ResultOfRound KMeans::complete_one_fitting_round(const Matrix& X) const
{
    std::vector<int> labels = initialize_round_clusters(X);
    Matrix potential_cluster_means;

    for( int i(0); i < m_n_it_per_round; ++i)
    {
        potential_cluster_means = calculate_means_by_cluster(X, labels);
        labels = reassign_clusters_by_new_cluster_mean(
            X, potential_cluster_means);
    }
    KMeans_Utils::ResultOfRound results{potential_cluster_means, labels};
    return results;
}

double KMeans::score_from_one_fitting_round(const Matrix& X,
            const Matrix& cluster_means,
            const std::vector<int> cluster_labels) const
{
    double score(0);
    DoubleVec associated_mean;
    DoubleVec observation;
    int label;
    for( int i(0); i < cluster_labels.size(); ++i)
    {
        observation = X.row(i);
        label = cluster_labels[i];
        associated_mean = cluster_means.col(label);
        score += (observation - associated_mean).sq_norm();
    }
    return score;
}

void KMeans::fit(const Matrix& X)
{
    double lowest_score = DBL_MAX;
    Matrix potential_new_means;
    KMeans_Utils::ResultOfRound result_from_round;
    double score_to_check;
    for( int i(0); i < m_n_rounds; ++i )
    {
        result_from_round = complete_one_fitting_round(X);
        score_to_check = score_from_one_fitting_round(X,
            result_from_round.cluster_means,
            result_from_round.cluster_labels);
        if(score_to_check < lowest_score)
            m_fitted_cluster_means = result_from_round.cluster_means;
    }
}

DoubleVec KMeans::predict(const Matrix& X) const
{
    DoubleVec v;
    DoubleVec obs;
    int closest_cluster;
    for(int i(0); i < X.nrow(); ++i)
    {
        obs = X.row(i);
        closest_cluster = find_closest_mean_to_observation(
            obs, m_fitted_cluster_means);
        v.push_back(closest_cluster);
    }
    return v;
}