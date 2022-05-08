// author: rgreer
#include <cmath>
#include "recombining_tree.hpp"
#include "parameterized_function.hpp"

RecombiningTree::RecombiningTree() {}

RecombiningTree::RecombiningTree(int n, double u, double r)
    : n(n), u(u), r(r) {}

// american option
RecombiningTree::RecombiningTree(int n, double u, double r,
                                 ParameterizedFunction final_function,
                                 ParameterizedFunction intermediate_function)
:final(final_function), intermediate(intermediate_function)
{
    RecombiningTree(n, u, r);
}

// european option
RecombiningTree::RecombiningTree(int n, double u, double r,
                    ParameterizedFunction final_function)
: final(final_function)
{
    RecombiningTree(n, u, r);
}

double RecombiningTree::price()
{
    return 0.;
}
