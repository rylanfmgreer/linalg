// author: rgreer
#include <float.h>
#include "k_means.hpp"
#include "../utility_functions.hpp"
#include "../doublevec_src/functions_on_doublevecs.hpp"

using namespace std; // TODO: remove

KMeans::KMeans(int n_means, int n_rounds, int n_iterations_per_round)
    : m_n_means(n_means), m_n_rounds(n_rounds),
      m_n_it_per_round(n_iterations_per_round)
{
}

Matrix KMeans::initialize_random_means(const Matrix &X) const
{
    // todo: save and reuse mins, maxs, etc.

    int ndim = X.ncol();
    DoubleVec mins = X.function_by_col(f_dv::min);
    DoubleVec maxs = X.function_by_col(f_dv::max);
    Matrix random_cluster_mean(ndim, m_n_means);
    double x;
    double minimum;
    double width;
    for (int r(0); r < ndim; ++r)
    {
        minimum = mins[r];
        width = maxs[r] - mins[r];

        for (int c(0); c < m_n_means; ++c)
        {
            x = mins[r] + width * util::crude_uniform_rv();
            random_cluster_mean(r, c) = x;
        }
    }
    return random_cluster_mean;
}

Matrix KMeans::initialize_random_means_from_data(const Matrix &X) const
{
    std::vector<int> chosen_data;
    int n_obs = X.nrow();
    Matrix cluster_choices;
    int obs_to_add_idx;
    bool obs_already_chosen;
    DoubleVec obs_to_add;
    for (int i(0); i < n_obs; ++i)
    {
        obs_already_chosen = true;
        while (obs_already_chosen)
        {
            obs_to_add_idx = util::rand_with_max_n(n_obs);
            obs_already_chosen = util::int_in_vector(obs_to_add_idx, chosen_data);
        }
        obs_to_add = X.row(obs_to_add_idx);
        cluster_choices.append_col(obs_to_add);
    }
    return cluster_choices;
}

std::vector<int> KMeans::initialize_round_clusters(int n_observations) const
{
    int n_means = m_n_means;
    std::vector<int> clusters(n_observations);
    std::transform(clusters.begin(),
                   clusters.end(),
                   clusters.begin(),
                   [n_means](int x)
                   { return util::rand_with_max_n(n_means); });
    return clusters;
}

Matrix KMeans::calculate_means_by_cluster(
    const Matrix &X, std::vector<int> cluster_labels) const
{
    std::vector<Matrix> matrices(m_n_means);
    int cluster_label;

    // build the matrices associated with each cluster
    for (int i(0); i < cluster_labels.size(); ++i)
    {
        cluster_label = cluster_labels[i];
        matrices[cluster_label].append_row(X.row(i));
    }

    // calculate the mean by column for each.
    Matrix potential_cluster_means;
    for (int i(0); i < m_n_means; ++i)
    {
        potential_cluster_means.append_col(
            matrices[i].mean_by_col());
    }
    return potential_cluster_means;
}

int KMeans::find_closest_mean_to_observation(
    const DoubleVec &observation,
    const Matrix &cluster_means) const
{
    double minimum_distance = DBL_MAX;
    int closest_cluster = -1;
    DoubleVec cluster_to_check;
    double distance_to_check;
    for (int i(0); i < m_n_means; ++i)
    {
        cluster_to_check = cluster_means.col(i);
        distance_to_check = (cluster_to_check - observation).sq_norm();
        if (distance_to_check < minimum_distance)
        {
            closest_cluster = i;
            minimum_distance = distance_to_check;
        }
    }
    return closest_cluster;
}

std::vector<int> KMeans::reassign_clusters_by_new_cluster_mean(
    const Matrix &X, const Matrix &cluster_means) const
{
    int n_observations = X.nrow();
    std::vector<int> new_clusters(n_observations);
    DoubleVec observation_to_check;
    for (int i(0); i < n_observations; ++i)
    {
        observation_to_check = X.row(i);
        new_clusters[i] = find_closest_mean_to_observation(
            observation_to_check, cluster_means);
    }
    return new_clusters;
}

KMeans_Utils::ResultOfRound KMeans::complete_one_fitting_round(const Matrix &X) const
{
    Matrix potential_cluster_means = initialize_random_means_from_data(X);
    std::vector<int> labels = reassign_clusters_by_new_cluster_mean(
        X, potential_cluster_means);
    for (int i(0); i < m_n_it_per_round - 1; ++i)
    {
        potential_cluster_means = calculate_means_by_cluster(X, labels);
        labels = reassign_clusters_by_new_cluster_mean(
            X, potential_cluster_means);
    }
    KMeans_Utils::ResultOfRound results{potential_cluster_means, labels};
    return results;
}

double KMeans::score_from_one_fitting_round(const Matrix &X,
                                            const Matrix &cluster_means,
                                            const std::vector<int> cluster_labels) const
{
    double score(0);
    DoubleVec associated_mean(0);
    DoubleVec observation(0);
    int label;
    for (int i(0); i < cluster_labels.size(); ++i)
    {
        observation = X.row(i);
        label = cluster_labels[i];
        associated_mean = cluster_means.col(label);
        score += (observation - associated_mean).sq_norm();
    }
    return score;
}

void KMeans::fit(const Matrix &X)
{
    assert(X.nrow() > m_n_means);
    double lowest_score = DBL_MAX;
    Matrix potential_new_means;
    KMeans_Utils::ResultOfRound result_from_round;
    double score_to_check;
    for (int i(0); i < m_n_rounds; ++i)
    {
        result_from_round = complete_one_fitting_round(X);
        score_to_check = score_from_one_fitting_round(X,
                                                      result_from_round.cluster_means,
                                                      result_from_round.cluster_labels);

        if (score_to_check < lowest_score)
        {
            m_fitted_cluster_means = result_from_round.cluster_means;
            lowest_score = score_to_check;
        }
    }
}

DoubleVec KMeans::predict(const Matrix &X) const
{
    DoubleVec v;
    DoubleVec obs;
    int closest_cluster;
    for (int i(0); i < X.nrow(); ++i)
    {
        obs = X.row(i);
        closest_cluster = find_closest_mean_to_observation(
            obs, m_fitted_cluster_means);
        v.push_back(closest_cluster);
    }
    return v;
}