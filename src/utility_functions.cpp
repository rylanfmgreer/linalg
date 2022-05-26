#include "utility_functions.hpp"
#include <vector>
#include <cmath>

using namespace std;

namespace util
{
    bool close(double x, double y, double epsilon)
    {
        return std::abs((x - y)) < epsilon;
    }

    bool int_in_vector(int n, vector<int> &v)
    {
        for (int i(0); i < v.size(); ++i)
        {
            if (n == v[i])
                return true;
        }
        return false;
    }

    bool double_in_vector(double x, vector<double> &v, double epsilon)
    {
        for( int i(0); i < v.size(); ++i )
        {
            if( close(v[i], x, epsilon) )
                return true;
        }
        return false;
    }
} // of namespace