#include "romberg_integrator.hpp"
#include "utility_functions.hpp"

void Romberg_Integrator_1D::initialize_step()
{
    m_step++;
    m_last_row = m_this_row();
    m_this_row.resize(m_step);

}
double Romberg_Integrator_1D::compute_h()
{
    double denominator = utils::compute_2_to_the_n(m_step);
    m_h = m_h_numerator/denominator;
}