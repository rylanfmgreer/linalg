// author: rgreer
#include <cmath>
#include "recombining_tree.hpp"

RecombiningTree::RecombiningTree() {}

RecombiningTree::RecombiningTree(int n, double u, double r)
    : n(n), u(u), r(r) {}

RecombiningTree::RecombiningTree(int n, double u, double r,
                                 std::function<double(double)> final_function,
                                 std::function<double(double)> intermediate_function)
    : final(final_function), intermediate(intermediate_function)
{
    RecombiningTree(n, u, r);
}

double RecombiningTree::price()
{
    double d = 1 / u;
    double p = (1 + r - d) / (u - d);
    double q = 1 - p;
    double r_ = r;
    double u_ = u;

    // 1. Forward pass -- create the final price vector
    DoubleVec v(n);
    DoubleVec w(n);

    v[0] = pow(d, n);
    std::transform(v.begin(), v.end() - 1, v.begin() + 1,
                   [u_](double x)
                   { return x * u_ * u_; });

    // 2. Price
    v.apply(final);

    for (int i(n - 1); i > 0; --i)
    {
        // 2.1 roll back
        w = v.deep_copy();
        std::transform(w.begin(), w.end() - 1, w.begin() + 1,
                       v.begin(), [r_, p, q](double x, double y)
                       { return (q * x + p * y) / (1 + r_); });
        v.apply(intermediate);
    }
    return v[0];
}
