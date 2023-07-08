#include <iostream>
#include <cmath>
#include "matrix.hpp"
#include "../doublevec_src/functions_on_doublevecs.hpp"
using namespace std;


int Matrix::nrow() const
{
    if (columns.size() == 0)
        return 0;
    return columns[0].size();
}

int Matrix::ncol() const
{
    return columns.size();
}

void Matrix::append_col(DoubleVec v)
{
    // TODO: add in special cases for empty matrix
    // we take in a vector for this one but a reference for append_row.
    columns.push_back(v);
}

void Matrix::append_row(DoubleVec v)
{
    // account for the case of an empty matrix
    if (this->nrow() == 0)
    {
        int n_rows_to_use = v.size();
        for (int i(0); i < n_rows_to_use; ++i)
        {
            DoubleVec empty_doublevec;
            columns.push_back(empty_doublevec);
        }
    }
    for (int i(0); i < columns.size(); ++i)
    {
        columns[i].push_back(v[i]);
    }
}

Matrix Matrix::deep_copy() const
{
    Matrix new_matrix(this->columns[0]);
    for (int i(1); i < this->ncol(); ++i)
    {
        new_matrix.append_col(this->columns[i]);
    }
    return new_matrix;
}

DoubleVec Matrix::row(int n) const
{
    int nr(columns[0].size());
    assert(n < nr);

    DoubleVec v(columns.size());
    for (int i(0); i < columns.size(); ++i)
    {
        v[i] = this->get(n, i);
    }
    return v;
}

DoubleVec Matrix::col(int n) const
{
    assert(n < columns.size());
    return columns[n].deep_copy();
}

double Matrix::get(int r, int c) const
{
    assert(r < columns[0].size());
    assert(c < columns.size());
    return columns[c].get(r);
}

Matrix Matrix::transpose() const
{
    int nr(this->nrow());
    int nc(this->ncol());
    Matrix new_matrix(nc, nr);
    for (int r(0); r < nr; ++r)
    {
        for (int c(0); c < nc; ++c)
        {
            new_matrix(c, r) = this->get(r, c);
        }
    }
    return new_matrix;
}

void Matrix::print() const
{
    for (int r(0); r < this->nrow(); ++r)
    {
        for (int c(0); c < this->ncol(); ++c)
        {
            cout << this->get(r, c) << ' ';
        }
        cout << endl;
    }
}

Matrix Matrix::matmul(const Matrix &A) const
{
    // regular matrix multiplication
    int lr = this->nrow();
    int lc = this->ncol();
    int rr = A.nrow();
    int rc = A.ncol();

    assert(lc == rr);
    Matrix new_matrix(lr, rc);

    for (int r(0); r < lr; ++r)
    {
        for (int c(0); c < rc; ++c)
        {
            DoubleVec row = this->row(r);
            DoubleVec col = A.col(c);
            new_matrix(r, c) = row * col;
        }
    }
    return new_matrix;
}

Matrix Matrix::apply(function<double(double)> f)
{
    Matrix new_matrix = this->deep_copy();
    for (int i(0); i < columns.size(); ++i)
    {
        new_matrix[i] = new_matrix[i].apply(f);
    }
    return new_matrix;
}

Matrix Matrix::drop_row(int n) const
{
    Matrix new_matrix = this->deep_copy();
    for (int i(0); i < this->ncol(); ++i)
    {
        new_matrix[i] = new_matrix[i].drop_index(n);
    }
    return new_matrix;
}

Matrix Matrix::drop_col(int n) const
{
    Matrix new_matrix = this->deep_copy();
    new_matrix.columns.erase(new_matrix.columns.begin() + n);
    return new_matrix;
}

bool Matrix::is_square() const
{
    return (this->nrow() == this->ncol());
}

bool Matrix::multiplicable(const Matrix &A) const
{
    // assumes this matrix is on the left and
    // a is on the right
    return (this->ncol() == A.nrow());
}

int Matrix::n_elements() const
{
    return (this->nrow() * this->ncol());
}

bool Matrix::invertible() const
{
    if (!this->is_square())
        return false;
    // account for numerical issues
    return std::abs(this->determinant()) > 1e-8;
}

void Matrix::set_row(const DoubleVec &v, int n)
{
    assert(n < nrow());
    assert(v.size() == ncol());

    for (int i(0); i < ncol(); ++i)
    {
        columns[i][n] = v.get(i);
    }
}

void Matrix::swap_rows(int r1, int r2)
{
    DoubleVec v1 = row(r1);
    DoubleVec v2 = row(r2);
    set_row(v2, r1);
    set_row(v1, r2);
}

Matrix Matrix::invert() const
{
    return inv(this->deep_copy());
}

bool Matrix::is_symmetric() const
{
    if (!this->is_square())
        return false;

    for (int r(1); r < this->nrow(); ++r)
    {
        for (int c(0); c < r; ++c)
        {
            if (this->get(r, c) != this->get(c, r))
                return false;
        }
    }

    return true;
}

DoubleVec Matrix::mean_by_col() const
{
    return this->function_by_col(f_dv::mean);
}

DoubleVec Matrix::function_by_col(std::function<double(DoubleVec)> f) const
{
    std::vector<double> values(this->ncol());
    DoubleVec col_to_apply_to;
    for (int i(0); i < this->ncol(); ++i)
    {
        col_to_apply_to = this->col(i);
        values[i] = f(col_to_apply_to);
    }
    DoubleVec dv(values);
    return dv;
}

DoubleVec Matrix::function_by_row(std::function<double(DoubleVec)> f) const
{
    Matrix AT = this->transpose();
    return AT.function_by_col(f);
}