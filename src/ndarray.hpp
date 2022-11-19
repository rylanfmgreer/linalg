// ndarray.hpp
// author: rgreer
// an attempt at a copycat of numpy's ndarray

#ifndef _ndarray_hpp_yukichan__
#define _ndarray_hpp_yukichan__

#include <vector>

class NDIndex
{
    public:
    NDIndex();
    NDIndex(const std::vector<unsigned int> p_sizes);

    unsigned int operator()( std::vector<unsigned int> p_pos );
    friend class NDArray;

    void set_orders( const std::vector<unsigned int> &v);
    std::vector<unsigned int> get_orders() const;
     
    void set_sizes( const std::vector<unsigned int> &v);
    std::vector<unsigned int> get_sizes() const;

    std::vector<unsigned int> get_skips(){ return m_skips; }

    private:
    std::vector<unsigned int> m_orders;
    std::vector<unsigned int> m_sizes;
    std::vector<unsigned int> m_skips;
    void calculate_skips();
    unsigned int vector_idx_to_flat_idx(
        const std::vector<unsigned int>& v ) const;
    std::vector<unsigned int> flat_idx_to_vector_idx(unsigned int n) const;

}; // end of class NDIndex

class NDArray
{
    public:
    NDArray();
    std::vector<double> m_data;
    friend class NDIndex;

    private:
    NDIndex m_index;

}; // end of class NDArray

#endif