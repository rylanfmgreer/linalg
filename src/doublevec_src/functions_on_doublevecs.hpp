#pragma once
#ifndef functions_on_doublevecs_hpp__rg
#define functions_on_doublevecs_hpp__rg
#include "doublevec.hpp"

namespace f_dv
{
    double mean(const DoubleVec &v);
    double max(const DoubleVec &v);
    double min(const DoubleVec &v);
};
#endif