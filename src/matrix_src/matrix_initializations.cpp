#include "matrix.hpp"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

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
        columns.push_back(DoubleVec(nr));
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

Matrix::Matrix(const Matrix& A)
{
    for( int i(0); i < A.ncol(); ++i)
        columns.push_back(A.col(i).deep_copy());
}

Matrix::Matrix(const std::string csv_filename,
    int start_row, bool ignore_first_column,
    bool ignore_first_row)
{
    // get the number of columns
    char separator(',');
    std::fstream csv;
    std::string line;
    int n_sep(0);
    csv.open(csv_filename);
    getline(csv, line);
    csv.close();
    std::for_each(line.begin(), line.end(),
                  [&n_sep, separator]( char ch )
                  {
                    n_sep += (ch == separator);
                  });
    int n_col = n_sep + 1;
    // pull these all into a vector
    std::vector<DoubleVec> dvs;
    int start_idx = ignore_first_column;
    for( int i(start_idx); i < n_col ; ++i )
    {
        DoubleVec v(csv_filename, i, ignore_first_row);
        dvs.push_back(v);
    }
    
    columns = dvs;  

}
