#include "matrix.hpp"
#include "utility_functions.hpp"
using namespace std;
using namespace util;

namespace inv_utils
{
    void backward( Matrix& A )
    {
        // this is a utility function. after we have the RREF,
        // complete the backward pass.
        int n = A.nrow();
        double x;
        
        for( int i(n - 1); i > 0; --i  )
        {
            for( int j(i - 1); j > -1; --j )
            {
                x = A.get(j, i);
                A.set_row( A.row(j) - x * A.row(i), j);
            }
        }
    }

} // end of namespace

Matrix inv( const Matrix& A )
{
    assert( A.invertible() );
    int n = A.nrow(); // == A.ncol()

    // begin the inversion process (Gaussian)
    // 1. set up the left side of the matrix
    Matrix inverter( n, 2 * n);
    for( int r(0); r < n; ++r )
    {
        for( int c(0); c < n; ++c )
        {
            inverter(r, c) = A.get(r, c);
        }
    }
    // 2. set up the right side of the matrix
    for( int i(0); i < n; ++i )
    {
        inverter(i, n + i) = 1.;
    }

    // 3. forward and backward pass
    inverter = rref(inverter);
    inv_utils::backward(inverter);

    // 4. copy in the new matrix
    Matrix inverse(n, n);
    for( int r(0); r < n; ++r )
    {
        for( int c(0); c < n; ++c )
        {
            inverse(r, c) = inverter.get(r, c + n);
        }
    }
    return inverse;
}