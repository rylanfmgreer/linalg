#include "utility_functions.hpp"
#include <vector>
#include <cmath>
#include <limits>
#include <random>
#include <stdexcept>

using namespace std;

namespace util
{
    bool close(const double x, const double y, const double epsilon)
    {
        return std::abs((x - y)) < epsilon;
    }

    bool int_in_vector(const int n, const vector<int> &v)
    {
        for (int i(0); i < v.size(); ++i)
        {
            if (n == v[i])
                return true;
        }
        return false;
    }

    bool double_in_vector(const double x, const vector<double> &v,
                          const double epsilon)
    {
        for (int i(0); i < v.size(); ++i)
        {
            if (close(v[i], x, epsilon))
                return true;
        }
        return false;
    }

    int int_pos_in_vector(const int n, const std::vector<unsigned int> &v)
    {
        for (int i(0); i < v.size(); ++i)
        {
            if (v[i] == n)
                return i;
        }
        return -1;
    }

    std::vector<unsigned int> argsort(const std::vector<unsigned int> &v)
    {
        vector<unsigned int> idx(v.size());
        std::iota(idx.begin(), idx.end(), 0);
        stable_sort(idx.begin(), idx.end(),
                    [&v](unsigned int i1, unsigned int i2)
                    { return v[i1] < v[i2]; });
        return idx;
    }

    int rand_from_0_to_n_exclusive_of_n(int n)
    {
        return std::rand() % n;
    }

    double crude_uniform_rv()
    {
        int lim = 100000;
        int val = std::rand() % lim;
        return (1.0 * val) / (1.0 * lim);
    }

    double crude_normal_rv()
    {
        double s = 0.;
        for (int i(0); i < 12; ++i)
        {
            s += crude_uniform_rv();
        }
        return (s - 6.);
    }

    int crude_double_to_int(double d)
    {
        double tol = 0.1;
        int n = static_cast<int>(d);
        double x = static_cast<double>(n);

        // check to see if we made it close the first time
        if( std::abs(x-d) < tol )
            return n;

        // will adding 1 help?
        n += 1;
        x += 1.0;
        if( std::abs(x-d) < tol )
            return n;

        // this probably won't help but its worth a shot
        n -= 2;
        x -= 2.0;
        if( std::abs(x-d) < tol )
            return n;

        throw exception();

        
    }

} // of namespace