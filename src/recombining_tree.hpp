// author: rgreer

#ifndef recombining_tree_hpp_fasaa
#define recombining_tree_hpp_fasaa

#include "doublevec.hpp"

class RecombiningTree
{
public:
    RecombiningTree();
    RecombiningTree(int n, double u, double r); // d = 1/u
    RecombiningTree(int n, double u, double r,
                    std::function<double(double)> final_function,
                    std::function<double(double)> intermediate_function);
    double price();

private:
    int n;
    double u;
    double r;
    std::function<double(double)> final;
    std::function<double(double)> intermediate;

}; // end of class RecombiningTree

#endif