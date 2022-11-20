#include "utility_functions.hpp"
#include <vector>
#include <cmath>
#include <limits>
#include <random>

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

    bool double_in_vector(const double x, const vector<double> &v,\
                          const double epsilon)
    {
        for( int i(0); i < v.size(); ++i )
        {
            if( close(v[i], x, epsilon) )
                return true;
        }
        return false;
    }

    int int_pos_in_vector(const int n, const std::vector<unsigned int> &v)
    {
       for (int i(0); i < v.size(); ++i)
       {
           if(v[i] == n)
            return i;
       }
       return -1;
    }


    std::vector<unsigned int> argsort(const std::vector<unsigned int>& v)
    {
        vector< unsigned int > idx(v.size());
        std::iota(idx.begin(), idx.end(), 0);
        stable_sort(idx.begin(), idx.end(),
            [&v](unsigned int i1, unsigned int i2) {return v[i1] < v[i2];});
        return idx;
    }

    int rand_with_max_n(int n)
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
        for( int i(0); i < 12; ++i)
        {
            s += crude_uniform_rv();
        }
        return s/12.;
    }

} // of namespace