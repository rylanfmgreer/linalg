// Author: rgreer
#pragma once
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
    Matrix(const DoubleVec p_v);

    /*
        Initialize a matrix with the vector of
        DoubleVecs as the columns.
    */
    Matrix(std::vector<DoubleVec> p_cols);

    /*
        Initialize the p_n p_x p_n identity matrix
    */
    Matrix(int p_n);

    /*
        Initialize a p_num_rows x p_num_cols matrix of all zeroes.
    */
    Matrix(int p_num_rows, int p_num_cols);


    /*
        Initialize a matrix as a copy of p_A.
    */
    Matrix(const Matrix& p_A);

    /*
        Read a matrix in from a filename
    */
    Matrix(const std::string p_csv_filename, int p_start_row=0,
           bool p_ignore_first_column=false, bool p_ignore_first_row=false);

    /*
        Pull the nth column. Allows modification (pulls reference.)
    */
    DoubleVec &operator[](int p_n);

    /*
        Pull the element at position p_r, p_c
        (or p_r + 1, p_c + 1 if using mathematical convention).
        Pulls by reference and so allows modification.
        To return the value, e.g. for use in non-const functions,
        use the get() operator, which works identically.

    */
    double &operator()(int p_r, int p_c);

    /*
        Add matrices.
    */
    Matrix operator+(const Matrix &p_A) const;

    /*
        Subtract matrices.
    */
    Matrix operator-(const Matrix &p_A) const;

    /*
        Wrapper for matrix multiplication.
        For elementwise multiplication, use elementwise( p_A )
    */
    Matrix operator*(const Matrix &p_A) const;

    /*
        Matrix multiplication with a vector.
        Ax = b

    */
    DoubleVec operator*(const DoubleVec &p_v) const;

    /*
        Multiplication of a matrix and a scalar
    */
    Matrix operator*(double p_x) const;

    /*
        Addition of a matrix and a scalar, provided as a convenience.
    */
    Matrix operator+(double p_x) const;

    /*
        Subtraction of a matrix and a scalar, provided as a convenience.
    */
    Matrix operator-(double p_x) const;

    /*
        Determines whether two matrices are equal.
    */
    bool operator==(const Matrix &p_A) const;

    /*
        Determines whether two matrices are not equal.
    */
    bool operator!=(const Matrix &p_A) const;

    /*
        Transpose operator for a matrix.

    */
    Matrix transpose() const;

    /*
        Pull the element at position p_r, c
        (or p_r + 1, c + 1 if using mathematical convention).
        Pulls by value and so does not allow modification.
        To return the reference, use the () operator.
    */
    double get(int p_r, int c) const;

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
    Matrix matmul(const Matrix &p_M) const;

    /*
        Pull the nth row (value, not reference.)
    */
    DoubleVec row(int p_n) const;

    /*
        Pull the nth column (value, not reference.)
    */
    DoubleVec col(int p_n) const;

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
        (p_f: R -> R)

    */
    Matrix apply(std::function<double(double)> p_f);

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
    bool multiplicable(const Matrix &p_A) const;

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
    Matrix drop_row(int p_n) const;

    /*
        Remove the nth column of a matrix.
    */
    Matrix drop_col(int p_n) const;

    /*
        For every element in v, remove that row.
    */
    Matrix drop_row(std::vector<int> &p_v) const;

    /*
        For every element in p_v, remove that column.
    */
    Matrix drop_col(std::vector<int> &p_v) const;

    /*
        Append p_v to the matrix's rows, if p_v has as many
        elements as the matrix has columns.
    */
    void append_row(DoubleVec p_v);

    /*
        Append p_v to the matrix's columns, if p_v has as many
        elements as the matrix has rows
    */
    void append_col(DoubleVec p_v);

    /*
        Print the values of the matrix.
    */
    void print() const;

    /*
        Replace row p_n of a matrix with p_v.
    */
    void set_row(const DoubleVec &p_v, int p_n);

    /*
        Swap row p_row_1 and row p_row_2.
    */
    void swap_rows(int p_row_1, int p_row_2);

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
    DoubleVec function_by_col(std::function<double(DoubleVec)> p_f) const;

    /*
        Apply a function by rows.
    */
    DoubleVec function_by_row(std::function<double(DoubleVec)> p_f) const;

    /*
        Get the sums by row.
    */
    DoubleVec sum_by_row() const;

    /*
        Get a version of the matrix
        where all the rows sum to one.
    */
    Matrix sum_to_one_by_row() const;

private:
    /*
        The columns of the matrix.
    */
    std::vector<DoubleVec> columns;
};

// convenience for ordering arguments. Identical to operators declared above.
inline Matrix operator*(double p_x, const Matrix &p_A) { return p_A * p_x; }
inline Matrix operator+(double p_x, const Matrix &p_A) { return p_A + p_x; }
inline Matrix operator-(double p_x, const Matrix &p_A) { return p_A - p_x; }
inline Matrix matmul(const Matrix &p_A, const Matrix &p_B) { return p_A.matmul(p_B); }

// other functions that will be useful:
// calculating determinant:
int find_best_row(const Matrix &p_A);
int find_best_col(const Matrix &p_A);
std::vector<Matrix> split_by_row(const Matrix &p_A, int p_n);
std::vector<Matrix> split_by_col(const Matrix &p_A, int p_n);
double det(const Matrix &p_A);
bool is_rref(const Matrix &p_A);

/*
    Return the row-reduced echelon form of p_A.
*/
Matrix rref(const Matrix &p_A);

/*
    invert p_A
*/
Matrix inv(const Matrix &p_A);

/*
    find the nullspace of p_A
*/
Matrix nullspace(const Matrix &p_A);

#endif