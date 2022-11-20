#include "matrix.hpp"
#include "../utilities_src/utility_functions.hpp"

using namespace std;
using namespace util;

namespace nullspace_utils
{
    // calculate which column has the pivot
    // for a given row v
    int pivot_column(const DoubleVec &v)
    {
        for (int i(0); i < v.size(); ++i)
        {
            if (!close(v.get(i)))
                return i;
        }
        return -1;
    }

    // for a given matrix A, find all columns
    // that have pivots
    vector<int> pivot_columns(const Matrix &A)
    {
        vector<int> pcs;
        for (int r(0); r < A.nrow(); ++r)
        {
            int pc = pivot_column(A.row(r));
            if (pc > -1)
                pcs.push_back(pc);
        }
        return pcs;
    }

    // get the last nonzero row of a matrix A
    int last_row(const Matrix &A)
    {
        DoubleVec z(A.ncol());
        for (int i(0); i < A.nrow(); ++i)
        {
            if (A.row(i) == z)
                return i - 1;
        }
        return A.nrow() - 1;
    }

    // backward elimintation in RREF
    void backward(Matrix &A)
    {
        int last_pivot(last_row(A));
        int pc;
        DoubleVec row;
        double x;
        for (int r(last_pivot); r > 0; --r)
        {
            pc = pivot_column(A.row(r));
            row = A.row(r);
            for (int j(r - 1); j > -1; --j)
            {
                x = A.get(j, pc);
                A.set_row(A.row(j) - x * row, j);
            }
        }
    }
}

Matrix reduced_form(const Matrix &A)
{
    Matrix B = A.deep_copy();
    B = rref(B);
    nullspace_utils::backward(B);
    return B;
}

Matrix nullspace(const Matrix &A)
{
    Matrix B = reduced_form(A);
    vector<DoubleVec> new_matrix;
    vector<int> pivot_columns = nullspace_utils::pivot_columns(B);

    // check every column
    for (int nc(0); nc < B.ncol(); ++nc)
    {
        // if it's not a pivot column:
        if (!int_in_vector(nc, pivot_columns))
        {
            // build list of pivot columns that come before
            vector<int> pivot_columns_before;
            for (int j(0); j < pivot_columns.size(); ++j)
            {
                if (pivot_columns[j] < nc)
                    pivot_columns_before.push_back(pivot_columns[j]);
            }

            // the pivots that come before need to be used to
            // nullify the entries in the non-pivot column.
            DoubleVec add(B.ncol());
            add[nc] = -1;
            for (int j(0); j < pivot_columns_before.size(); ++j)
            {
                add[pivot_columns_before[j]] = B.get(j, nc);
            }
            new_matrix.push_back(add);
        }
    }

    // put these in a matrix and return it
    Matrix C(new_matrix);
    return C;
}