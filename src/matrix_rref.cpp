#include "matrix.hpp"
#include "utility_functions.hpp"

/*
    this could definitely be optimized
    (early cutoff for rref, etc)
*/

using namespace std;
using namespace util;

int next_pivot_row(const Matrix &A, int r, int c)
{
    // kill condition
    if (r == A.nrow())
        return -1;

    // continue
    for (int i(r); i < A.nrow(); ++i)
    {
        if (!close(A.get(i, c), 0.))
        {
            return i;
        }
    }

    // kill if no nonzero row exists
    return -1;
}

void pivot_swap(Matrix &A, int r, int c)
{
    int npr = next_pivot_row(A, r, c);
    if (npr != r && (npr >= 0))
    {
        A.swap_rows(r, npr);
    }
}

vector<int> nonzero_cols(Matrix &A)
{
    vector<int> v;
    DoubleVec zero(A.nrow());
    DoubleVec col;
    for (int i(0); i < A.ncol(); ++i)
    {
        col = A[i];
        if (col != zero)
            v.push_back(i);
    }
    return v;
}

Matrix rref(const Matrix &A)
{
    Matrix B = A.deep_copy(); // copy that we will eventually return
    vector<int> nzc = nonzero_cols(B);
    int npr = next_pivot_row(B, 0, 0);
    int r = 0;
    int ci = 0;
    int c = nzc[ci];
    double x, y;

    while ((r < B.nrow()) && (ci < nzc.size()))
    {
        pivot_swap(B, r, c);
        B.set_row(B.row(r) * (1 / B.get(r, c)), r);
        for (int i(r + 1); i < B.nrow(); ++i)
        {
            double y = B.get(i, c);
            B.set_row(B.row(i) - y * B.row(r), i);
        }
        r++;
        ci++;
        c = nzc[ci];
    }
    return B;
}