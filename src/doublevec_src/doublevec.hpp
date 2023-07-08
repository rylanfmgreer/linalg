#pragma once
#ifndef doublevec_hpp___1234567654321
#define doublevec_hpp___1234567654321

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// In depth description of member functions given in .cpp file
class DoubleVec
{
public:
    /*
        Empty vector initialization
    */
    DoubleVec();

    /*
        Initialize with p_v as the elements.
    */
    DoubleVec(const std::vector<double> &p_f);

    /*
        Vector with p_n elements, all set to zero.
    */
    DoubleVec(int p_n);

    /*
        Initialize a vector with the elements of p_v.
    */
    DoubleVec(const DoubleVec &p_v);

    /*
        Vector with p_n elements, all set to p_x
    */
    DoubleVec(int p_n, double p_x);

    /*
        Worse version of numpy.arange.
        Begin at p_start, p_end at p_end, elements are spaced by p_step.
        The vector will have  [(p_end - p_start) // p_step + 1] elements.
    */
    DoubleVec(double p_start, double p_end, double p_step); // think worse version of np.arange! 

    /*
        Hacked together solution to read a single vector from a csv.
    */
    DoubleVec(const std::string p_filename, int p_col_number, int p_start_row);

    /*
        Add two vectors (elementwise addition)
    */
    DoubleVec operator+(const DoubleVec &p_v) const;

    /*
        Add a scalar to a vector
    */
    DoubleVec operator+(const double p_additor) const;

    /*
        Subtract two vectors (elementwise)
    */
    DoubleVec operator-(const DoubleVec &p_v) const;

    /*
        Subtract a scalar from a vector
    */
    DoubleVec operator-(const double p_subtractor) const;

    /*
        Vector dot product
    */
    double operator*(const DoubleVec &p_v) const;

    /*
        Scalar multiplication of a vector
    */
    DoubleVec operator*(const double p_scalar) const;

    /*
        Scalar division of a vector
    */
    DoubleVec operator/(const double p_denominator) const;

    /*
        Elementwise division of a vector
    */
    DoubleVec operator/(const DoubleVec& p_v) const;

    /*
        Determine whether two vectors are equal
    */
    bool operator==(const DoubleVec &p_v) const;

    /*
        Determine whether two vectors are not equal
    */
    bool operator!=(const DoubleVec &p_v) const;

    /*
        Concatenate two vectors.
    */
    DoubleVec concat(const DoubleVec &p_v) const;

    /*
        Elementwise multiplication of two vectors.
    */
    DoubleVec elementwise(const DoubleVec &p_v) const;

    /*
        Deep copy of a vector
    */
    DoubleVec deep_copy() const;

    /*
        Apply a function f to every element of a vector
        (f: R -> R)
    */
    DoubleVec apply(std::function<double(double)> p_f) const;

    /*
        Drop the nth element of a vector.
        Not in-place
    */
    DoubleVec drop_index(int p_n) const;

    /*
        For every index in p_v, drop that element
        from the vector. Not in-place.
    */
    DoubleVec drop_index(std::vector<int> v) const;

    /*
        Return a reference to the nth element of a vector.
    */
    double &operator[](int n);

    /*
        Append a double to a vector.
    */
    void push_back(double v) { m_data.push_back(v); }

    /*
        Print every element of a vector
    */
    void print();

    /*
        Return the number of elements in a vector.
    */
    int size() const { return m_data.size(); }

    /*
        Return a sorted version of a vector.
    */
    DoubleVec sort() const;

    /*
        Return whether the number v is in the vector.
    */
    bool is_in(double v) const;

    /*
        Return the rth value in the vector.
        this returns a value, not a reference,
        and so cannot be used for assignment.

        To assign, use the [] operator.
    */
    double get(int p_r) const;

    /*
        Return the number of times p_v appears in the vector
    */
    int count(double p_v, double p_tolerance = 1e-8) const;
    
    /*
        Return the dot product of this and v
    */
    double dot(const DoubleVec& p_v) const;

    /*
        Return a copy of DoubleVec
        where it sums to 1.
    */
    DoubleVec normalize() const;

    /*
        Modify doublevec in place so that it sums to one
    */
    void normalize_inplace();

    // Basic statistical functions.
    double sum() const;
    double mean() const;
    double var() const;
    double stdev() const;
    double max() const;
    double min() const;
    double cov(const DoubleVec &v) const;
    double cor(const DoubleVec &v) const;

    // other often useful functions
    DoubleVec cumsum() const; // cumulative sum
    double sq_norm() const;   // squared euclidean norm
    double norm() const;      // euclidean norm

    /*
    Rolling sum and mean.
    */
    DoubleVec rolling_sum(int p_n_elements, int p_n_offset) const;
    DoubleVec rolling_mean(int p_n_elements, int p_n_offset) const;
    DoubleVec centered_rolling_mean(int p_n_elements) const;

    // member data
    std::vector<double> m_data;

    // iterator
    typedef std::vector<double>::iterator iterator;
    typedef std::vector<double>::const_iterator const_iterator;
    iterator begin() { return m_data.begin(); }
    iterator end() { return m_data.end(); }

    private:
};

// non-member functions for easy addition and multiplication
inline DoubleVec operator+(double p_x, const DoubleVec &p_v) { return p_v + p_x; }
inline DoubleVec operator*(double p_x, const DoubleVec &p_v) { return p_v * p_x; }
inline DoubleVec operator-(double p_x, const DoubleVec &p_v) { return -1. * (p_v - p_x); }
inline DoubleVec operator/(double p_x, const DoubleVec &p_v) { return p_v * (1 / p_x); }

// statistics functions that can be called on an individual doublevec
// which are just a wrapper for the functions given above.
double sum(const DoubleVec &p_v);
double mean(const DoubleVec &p_v);
double var(const DoubleVec &p_v);
double stdev(const DoubleVec &p_v);
double cov(const DoubleVec &p_v, const DoubleVec &p_w);
double cor(const DoubleVec &p_v, const DoubleVec &p_w);

DoubleVec cumsum(const DoubleVec &v);

#endif
