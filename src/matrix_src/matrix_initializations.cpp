#include "matrix.hpp"
using namespace std;

Matrix::Matrix()
{
    std::vector<DoubleVec> columns;
}

Matrix::Matrix(const DoubleVec v)
{
    // one column; exactly what you are given
    columns.push_back(v);
}

Matrix::Matrix(std::vector<DoubleVec> cols)
{
    // just use the columns given
    columns = cols;
}

Matrix::Matrix(int nr, int nc)
{
    // all zero matrix
    for (int i(0); i < nc; ++i)
    {
        columns.push_back(DoubleVec(nr));
    }
}

Matrix::Matrix(int n)
{
    // identity matrix
    for (int i(0); i < n; ++i)
    {
        DoubleVec nv(n);
        nv[i] = 1.;
        columns.push_back(nv);
    }
}