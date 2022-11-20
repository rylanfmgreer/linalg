// Author: rgreer
#ifndef _matrix_hpp_fosun___
#define _matrix_hpp_fosun___

#include "../doublevec_src/doublevec.hpp"
#include <vector>

class Matrix
{
public:
    // initializations
    /*
        Initialize an empty matrix.
    */
    Matrix();

    /*
        Initialize a matrix with just the one vector
        as a column.
    */
    Matrix(const DoubleVec v);

    /*
        Initialize a matrix with the vector of
        DoubleVecs as the columns.
    */
    Matrix(std::vector<DoubleVec> cols);

    /*
        Initialize the n x n identity matrix
    */
    Matrix(int n);

    /*
        Initialize a nr x nc matrix of all zeroes.
    */
    Matrix(int nr, int nc);

    /*
        Pull the nth column. Allows modification (pulls reference.)
    */
    DoubleVec &operator[](int n);

    /*
        Pull the element at position r, c
        (or r + 1, c + 1 if using mathematical convention).
        Pulls by reference and so allows modification.
        To return the value, e.g. for use in non-const functions,
        use the get() operator, which works identically.

    */
    double &operator()(int r, int c);

    /*
        Add matrices.
    */
    Matrix operator+(const Matrix &A) const;

    /*
        Subtract matrices.
    */
    Matrix operator-(const Matrix &A) const;

    /*
        Wrapper for matrix multiplication.
        For elementwise multiplication, use elementwise( A )
    */
    Matrix operator*(const Matrix &A) const;

    /*
        Matrix multiplication with a vector.
        Ax = b

    */
    DoubleVec operator*(const DoubleVec &v) const;

    /*
        Multiplication of a matrix and a scalar
    */
    Matrix operator*(double x) const;

    /*
        Addition of a matrix and a scalar, provided as a convenience.
    */
    Matrix operator+(double x) const;

    /*
        Subtraction of a matrix and a scalar, provided as a convenience.
    */
    Matrix operator-(double x) const;

    /*
        Determines whether two matrices are equal.
    */
    bool operator==(const Matrix &A) const;

    /*
        Determines whether two matrices are not equal.
    */
    bool operator!=(const Matrix &A) const;

    /*
        Transpose operator for a matrix.

    */
    Matrix transpose() const;

    /*
        Pull the element at position r, c
        (or r + 1, c + 1 if using mathematical convention).
        Pulls by value and so does not allow modification.
        To return the reference, use the () operator.
    */
    double get(int r, int c) const;

    /*
        Return a deep copy of the matrix.
    */
    Matrix deep_copy() const;

    /*
        Invert the matrix if possible.
    */
    Matrix invert() const;

    /*
        Matrix multiplication.
    */
    Matrix matmul(const Matrix &M) const;

    /*
        Pull the nth row (value, not reference.)
    */
    DoubleVec row(int n) const;

    /*
        Pull the nth column (value, not reference.)
    */
    DoubleVec col(int n) const;

    /*
        Calculate the determinant of a square matrix.
    */
    double determinant() const;

    /*
        Return the number of rows in the matrix.
    */
    int nrow() const;

    /*
        Return the number of columns in the matrix
    */
    int ncol() const;

    /*
        Apply a single valued function to every element of a matrix.
        (f: R -> R)

    */
    Matrix apply(std::function<double(double)> f);

    /*
        Wrapper for the transpose of a matrix.
        Identical to matrix.transpose()
    */
    Matrix T() const { return this->transpose(); }

    /*
        Determine whether a matrix is square.
    */
    bool is_square() const;

    /*
        Determine whether two matrices are multiplicable
    */
    bool multiplicable(const Matrix &A) const;

    /*
        Determine the mumbner of elements in a matrix.
    */
    int n_elements() const;

    /*
        Determine whether a matrix is invertible.
    */
    bool invertible() const;

    /*
        Remove the nth row of a matrix.
    */
    Matrix drop_row(int n) const;

    /*
        Remove the nth column of a matrix.
    */
    Matrix drop_col(int n) const;

    /*
        For every element in v, remove that row.
    */
    Matrix drop_row(std::vector<int> &v) const;

    /*
        For every element in v, remove that column.
    */
    Matrix drop_col(std::vector<int> &v) const;

    /*
        Append v to the matrix's rows, if v has as many
        elements as the matrix has columns.
    */
    void append_row(DoubleVec v);

    /*
        Append v to the matrix's columns, if v has as many
        elements as the matrix has rows
    */
    void append_col(DoubleVec v);

    /*
        Print the values of the matrix.
    */
    void print() const;

    /*
        Replace row n of a matrix with v.
    */
    void set_row(const DoubleVec &v, int n);

    /*
        Swap row r1 and row r2.
    */
    void swap_rows(int r1, int r2);

    /*
        Determine whether a matrix is symmetric
    */
    bool is_symmetric() const;

    /*
        Calculate the mean of each column
        and return them as a doublevec.
    */
    DoubleVec mean_by_col() const;

    /*
        Apply a function by columns.
    */
    DoubleVec function_by_col(std::function<double(DoubleVec)> f) const;


    /*
        Apply a function by rows.
    */
    DoubleVec function_by_row(std::function<double(DoubleVec)> f) const;


private:
    /*
        The columns of the matrix.
    */
    std::vector<DoubleVec> columns;
};

// convenience for ordering arguments. Identical to operators declared above.
inline Matrix operator*(double x, const Matrix &A) { return A * x; }
inline Matrix operator+(double x, const Matrix &A) { return A + x; }
inline Matrix operator-(double x, const Matrix &A) { return A - x; }
inline Matrix matmul(const Matrix &A, const Matrix &B) { return A.matmul(B); }

// other functions that will be useful:
// calculating determinant:
int find_best_row(const Matrix &A);
int find_best_col(const Matrix &A);
std::vector<Matrix> split_by_row(const Matrix &A, int n);
std::vector<Matrix> split_by_col(const Matrix &A, int n);
double det(const Matrix &A);
bool is_rref(const Matrix &A);

/*
    Return the row-reduced echelon form of A.
*/
Matrix rref(const Matrix &A);

/*
    invert A
*/
Matrix inv(const Matrix &A);

/*
    find the nullspace of A
*/
Matrix nullspace(const Matrix &A);

#endif