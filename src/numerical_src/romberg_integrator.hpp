#include <vector>
#include "integrator_1d.hpp"

class Romberg_Integrator_1D: public Integrator_1D
{

    private:
    void compute_h();
    std::vector<double> m_this_row;
    std::vector<double> m_last_row;
    
}