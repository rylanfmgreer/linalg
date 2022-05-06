#include "matrix.hpp"
using namespace std;


DoubleVec& Matrix::operator[] (int n)
{
    // return the column requested
    return columns[n];
}


double& Matrix::operator() (int r, int c)
{
    // return a _reference_ to the index
    return columns[c][r];
}


Matrix Matrix::operator+ (const Matrix& A) const
{
    // match the shapes
    assert( this->nrow() == A.nrow() );
    assert( this->ncol() == A.ncol() );

    Matrix new_matrix( A.nrow(), A.ncol() );
    for( int c(0); c < A.ncol(); ++c )
    {
        new_matrix[c] = A.col(c) + columns[c];
    }
    return new_matrix;
}


Matrix Matrix::operator* (double x) const
{

    Matrix new_matrix( this->nrow(), this->ncol() );
    for( int c(0); c < this->ncol(); ++c )
    {
        new_matrix[c] = columns[c] * x;
    }
    return new_matrix;
}


Matrix Matrix::operator* (const Matrix& A) const
{
    // matrix multiplication, implemented elsewhere.
    return this->matmul(A);
}

DoubleVec Matrix::operator* (const DoubleVec& v) const
{
    // matrix multiplication, implemented elsewhere.
    // This is "code efficient" but not "memory efficient."
    Matrix A(v);
    Matrix B = this->matmul(A);
    return B[0];
}


bool Matrix::operator== (const Matrix& A) const
{
    // false if the sizes are not the same
    if( this->ncol() != A.ncol() )
        return false;
    if( this->nrow() != A.nrow() )
        return false;

    // vectorwise comparison
    // (this is not efficient; vectors are still elementwise)
    for( int i(0); i < A.ncol(); ++i )
    {
        if(  (columns[i] != A.col(i) ) )
            return false;
    }
    return true;
}

bool Matrix::operator!= (const Matrix& A) const
{
    // early kills
    if( this->ncol() != A.ncol() )
        return true;

    for( int i(0); i < A.ncol(); ++i )
    {
        if(  !(columns[i] != A.col(i) ) )
            return true;
    }
    return false;
}


Matrix Matrix::operator+ ( double x ) const
{
    Matrix new_matrix = this->deep_copy();
    for( int i(0); i < this->ncol(); ++i )
    {
        new_matrix[i] = new_matrix[i] + x;
    }
    return new_matrix;
}


Matrix Matrix::operator- ( double x ) const
{
    return *this + (-1 * x);
}
