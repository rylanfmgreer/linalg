#ifndef utility_functions_at8____
#define utility_functions_at8____
#include <vector>
#include <numeric>
/*
    This is a set of simple functions that are useful in a lot of contexts.
*/

namespace util
{
    /*
        Determine whether two numbers are arbitrarily close.
        Numerical precision is given by 1e-8 by default but can be changed.
    */
    bool close(const double x, const double y = 0.0,
                const double epsilon = 1e-8);

    /*
        Determine whether an int is present in a vector.
    */
    bool int_in_vector(const int n, const std::vector<int> &v);

    /*
        Find the position of int n in vector v
    */
    int int_pos_in_vector(const int n, const std::vector<unsigned int> &v);

    /*
        Determine whether a number arbitrarily close to
        x is in a vector
    */
    bool double_in_vector(double x, const std::vector<double> &v,
                         double epsilon=1e-8);

    std::vector<unsigned int> argsort( const std::vector<unsigned int>& v);

    int rand_with_max_n(int n);

    double crude_uniform_rv();
    double crude_normal_rv();
}

#endif