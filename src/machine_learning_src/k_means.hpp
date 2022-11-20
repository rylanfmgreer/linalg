// author: rgreer
#ifndef k_means_hpp_____
#define k_means_hpp_____

#include "machine_learning.hpp"

namespace KMeans_Utils
{
    struct ResultOfRound
    {
        public:
        Matrix cluster_means;
        std::vector<int> cluster_labels;
    };

}; // end of namespace

class KMeans: public UnsupervisedLearning
{
    public:
    KMeans(int n_means, int n_rounds, int n_iterations_per_round);
    virtual void fit(const Matrix& X);
    virtual DoubleVec predict(const Matrix& X) const;
    
    private:
    Matrix m_fitted_cluster_means;
    int m_n_means;
    int m_n_rounds;
    int m_n_it_per_round;

    // for the fitting algorithm
    // high-level functions
    KMeans_Utils::ResultOfRound complete_one_fitting_round(
        const Matrix& X) const;
        
    double score_from_one_fitting_round(const Matrix& X,
            const Matrix& cluster_means,
            const std::vector<int> cluster_labels) const;

    // lower level within-round functions
    std::vector<int> initialize_round_clusters(int n_observations) const;

    Matrix calculate_means_by_cluster(const Matrix& X,
                std::vector<int> cluster_labels) const;

    std::vector<int> reassign_clusters_by_new_cluster_mean(
        const Matrix& X, const Matrix& cluster_means) const;

    int find_closest_mean_to_observation(const DoubleVec& observation,
            const Matrix& cluster_means) const;

}; // end of class


#endif