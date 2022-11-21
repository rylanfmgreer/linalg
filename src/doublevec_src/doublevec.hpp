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
        Initialize with v as the elements.
    */
    DoubleVec(const std::vector<double> &v);

    /*
        Vector with n elements, all set to zero.
    */
    DoubleVec(int n);

    /*
        Initialize a vector with the elements of v.
    */
    DoubleVec(const DoubleVec &v);

    /*
        Vector with n elements, all set to x
    */
    DoubleVec(int n, double x);

    /*
        Worse version of numpy.arange.
        Begin at start, end at end, elements are spaced by step.
        The vector will have  [(end - start) // step + 1] elements.
    */
    DoubleVec(double start, double end, double step); // think worse version of np.arange! 

    /*
        Hacked together solution to read a single vector from a csv.
    */
    DoubleVec(const std::string filename, int column_number, int start_row);

    /*
        Add two vectors (elementwise addition)
    */
    DoubleVec operator+(const DoubleVec &v) const;

    /*
        Add a scalar to a vector
    */
    DoubleVec operator+(const double scalar) const;

    /*
        Subtract two vectors (elementwise)
    */
    DoubleVec operator-(const DoubleVec &v) const;

    /*
        Subtract a scalar from a vector
    */
    DoubleVec operator-(const double scalar) const;

    /*
        Vector dot product
    */
    double operator*(const DoubleVec &v) const;

    /*
        Scalar multiplication of a vector
    */
    DoubleVec operator*(const double scalar) const;

    /*
        Determine whether two vectors are equal
    */
    bool operator==(const DoubleVec &v) const;

    /*
        Determine whether two vectors are not equal
    */
    bool operator!=(const DoubleVec &v) const;

    /*
        Concatenate two vectors.
    */
    DoubleVec concat(const DoubleVec &v) const;

    /*
        Elementwise multiplication of two vectors.
    */
    DoubleVec elementwise(const DoubleVec &v) const;

    /*
        Deep copy of a vector
    */
    DoubleVec deep_copy() const;

    /*
        Apply a function f to every element of a vector
        (f: R -> R)
    */
    DoubleVec apply(std::function<double(double)> f) const;

    /*
        Drop the nth element of a vector.
        Not in-place
    */
    DoubleVec drop_index(int n) const;

    /*
        For every index in v, drop that element
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
    void push_back(double v) { data.push_back(v); }

    /*
        Print every element of a vector
    */
    void print();

    /*
        Return the number of elements in a vector.
    */
    int size() const { return data.size(); }

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
    double get(int r) const;

    /*
        Return the number of times v appears in the vector
    */
    int count(double v, double eps = 1e-8) const;
    
    /*
        Return the dot product of this and v
    */
    double dot(const DoubleVec& v) const;

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

    // member data
    std::vector<double> data;

    // iterator
    typedef std::vector<double>::iterator iterator;
    typedef std::vector<double>::const_iterator const_iterator;
    iterator begin() { return data.begin(); }
    iterator end() { return data.end(); }
};

// non-member functions for easy addition and multiplication
inline DoubleVec operator+(double x, const DoubleVec &v) { return v + x; }
inline DoubleVec operator*(double x, const DoubleVec &v) { return v * x; }
inline DoubleVec operator-(double x, const DoubleVec &v) { return -1. * (v - x); }
inline DoubleVec operator/(double x, const DoubleVec &v) { return v * (1 / x); }

// statistics functions that can be called on an individual doublevec
// which are just a wrapper for the functions given above.
double sum(const DoubleVec &v);
double mean(const DoubleVec &v);
double var(const DoubleVec &v);
double stdev(const DoubleVec &v);
double cov(const DoubleVec &v, const DoubleVec &w);
double cor(const DoubleVec &v, const DoubleVec &w);

DoubleVec cumsum(const DoubleVec &v);

#endif
