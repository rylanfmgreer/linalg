// ndarray.cpp
// author: rgreer

#include "ndarray.hpp"
#include "utility_functions.hpp"
#include <numeric>

typedef unsigned int usi;

NDIndex::NDIndex(){}

NDIndex::NDIndex( const std::vector<usi> p_sizes )
:m_sizes(p_sizes)
{
    // default initialization of m_orders:
    std::vector<usi> m_orders(p_sizes.size());
    std::transform(m_orders.begin(), m_orders.end() - 1,
                   m_orders.begin() + 1, [](usi x)
                   { return x + 1; });
}

void NDIndex::calculate_skips()
{
    /*
        lets us know how much to skip through to get each axis

        vector: [a b c d e f g h i]
        shape: [3 3]

        order 1: [0 1]
        view 1: [a b c
                 d e f
                 g h i]

        order 2: [1 0]
        view 2: [a d g
                 b e h
                 c f i]
    */
    
    std::vector<usi> new_skips_vector( m_orders.size() );
    usi cumulative_product(1);
    int idx;
    for( usi i_order(0); i_order < new_skips_vector.size(); ++i_order )
    {
        idx = util::int_pos_in_vector(i_order, this->m_orders);
        new_skips_vector[idx] = cumulative_product;
        cumulative_product *= m_sizes[idx];
    }
    m_skips = new_skips_vector;
}

usi NDIndex::vector_idx_to_flat_idx( const std::vector<usi>& v ) const
{
    // turn a vector of indexes in the ndarray into a flat index
    return std::inner_product( v.begin(), v.end(), m_skips.begin(), 0 );
}

std::vector<usi> NDIndex::flat_idx_to_vector_idx( const usi n) const
{
    std::vector<usi> v;

    // algorithm: go down the 
    
    return v;

}