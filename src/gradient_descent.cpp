#include "doublevec_src/doublevec.hpp"
#include "parameterized_function.hpp"

DoubleVec gradient(std::function<double(DoubleVec)> f,
                   DoubleVec x, double eps = 1e-6)
{
    std::vector<double> v(x.size());
    double fx = f(x);
    for (int i(0); i < v.size(); ++i)
    {
        x[i] += eps;
        v[i] = f(x);

        x[i] -= 2 * eps;
        v[i] -= f(x);
        v[i] = v[i] / (2 * eps);

        x[i] += eps;
    }
    return DoubleVec(v);
}

DoubleVec gradient_descent(ParameterizedFunction pf,
                           DoubleVec initial_guess)
{
    DoubleVec v;
    return v;
}