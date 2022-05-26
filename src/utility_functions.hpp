#ifndef utility_functions_at8____
#define utility_functions_at8____
#include <vector>
/*
    This is a set of simple functions that are useful in a lot of contexts.
*/

namespace util
{
    /*
        Determine whether two numbers are arbitrarily close.
        Numerical precision is given by 1e-8 by default but can be changed.
    */
    bool close(double x, double y = 0.0, double epsilon = 1e-8);

    /*
        Determine whether an int is present in a vector.
    */
    bool int_in_vector(int n, std::vector<int> &v);


    /*
        Determine whether a number arbitrarily close to
        x is in a vector
    */
   bool double_in_vector(double x, std::vector<double> &v,
                         double epsilon=1e-8);

}

#endif