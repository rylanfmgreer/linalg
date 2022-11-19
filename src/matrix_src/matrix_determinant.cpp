#include "matrix.hpp"
#include <cmath>
using namespace std;

double det_operation(const DoubleVec &split_obj,
                     const DoubleVec &subdeterminants, int split_num)
{
    // add then subtract then add then subtract then...
    // this lets us know where to start, and we accumulate
    // going forward.
    int scalar = 1;
    for (int i(0); i < split_num; ++i)
    {
        scalar *= -1;
    }

    double det(0);
    for (int i(0); i < split_obj.size(); ++i)
    {
        det += split_obj.get(i) * subdeterminants.get(i) * scalar;
        scalar *= -1;
    }
    return det;
}

std::vector<Matrix> split_by_row(const Matrix &A, int n)
{
    assert(n < A.nrow());
    Matrix base_matrix = A.deep_copy();
    base_matrix = base_matrix.drop_row(n);
    std::vector<Matrix> return_matrices;
    for (int i(0); i < A.ncol(); ++i)
    {
        return_matrices.push_back(base_matrix.drop_col(i));
    }
    return return_matrices;
}

std::vector<Matrix> split_by_col(const Matrix &A, int n)
{
    assert(n < A.ncol());
    Matrix base_matrix = A.deep_copy();
    base_matrix = base_matrix.drop_col(n);
    std::vector<Matrix> return_matrices;
    for (int i(0); i < A.nrow(); ++i)
    {
        return_matrices.push_back(base_matrix.drop_row(i));
    }
    return return_matrices;
}

double det(const Matrix &A)
{
    /*
    This is a naïve operation as of now that does not
    yet look to find the "best" split.
    It simply splits using the first row of the matrix every time.
    */

    // This function is recursive; this is the end state.
    assert(A.is_square());
    if (A.n_elements() == 1)
        return A.get(0, 0);

    // to optimize the code somewhat we can update this section.
    int split_num = 0;
    std::vector<Matrix> split_matrices = split_by_row(A, split_num);
    DoubleVec split_obj = A.row(split_num);
    // end of section that would benefit from an update
    // ( although there could well be others! )

    // calculate the determinant on the submatrices.
    std::vector<double> determinants(split_matrices.size());
    for (int i(0); i < split_matrices.size(); ++i)
    {
        determinants[i] = det(split_matrices[i]);
    } // recursive call
    DoubleVec subdeterminants(determinants);
    return det_operation(split_obj, subdeterminants, split_num);
}

double Matrix::determinant() const
{
    return det(*this);
}