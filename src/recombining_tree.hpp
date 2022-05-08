// author: rgreer

#ifndef recombining_tree_hpp_fasaa
#define recombining_tree_hpp_fasaa

#include "doublevec.hpp"
#include "parameterized_function.hpp"

class RecombiningTree
{
public:

    RecombiningTree(int n, double u, double r); // d = 1/u

    // american option
    RecombiningTree(int n, double u, double r,
                    ParameterizedFunction final_function,
                    ParameterizedFunction intermediate_function);

    // european option
    RecombiningTree(int n, double u, double r,
                    ParameterizedFunction final_function);

    // price the option
    double price();

private:
    RecombiningTree();
    int n;
    double u;
    double r;
    ParameterizedFunction final;
    ParameterizedFunction intermediate;

}; // end of class RecombiningTree

#endif