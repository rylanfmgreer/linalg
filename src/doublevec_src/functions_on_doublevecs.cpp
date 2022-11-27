#include "functions_on_doublevecs.hpp"
#include <float.h>
namespace f_dv
{
    double mean(const DoubleVec &v)
    {
        return v.mean();
    }

    double max(const DoubleVec &v)
    {
        return v.max();
    }

    double min(const DoubleVec &v)
    {
        return v.min();
    }

};