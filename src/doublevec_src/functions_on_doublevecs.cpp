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
        double mx = -1.0 * DBL_MAX;
        std::for_each(v.m_data.begin(), v.m_data.end(),
                      [&mx](double x)
                      {
                          if (x > mx)
                              mx = x;
                      });
        return mx;
    }

    double min(const DoubleVec &v)
    {
        double mn = DBL_MAX;
        std::for_each(v.m_data.begin(), v.m_data.end(),
                      [&mn](double x)
                      {
                          if (x < mn)
                              mn = x;
                      });
        return mn;
    }

};