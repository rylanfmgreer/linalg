#include "src/doublevec.hpp"
#include "src/matrix.hpp"
#include <iostream> 

using namespace std;

int main()
{
    Matrix A(2);
    Matrix B(2);
    A(1, 0) = 5;
    B(0, 1) = 3;
    Matrix C = A.matmul(B);
    C.print();

    C = C + 5;
    C.print();

    C = C * 3;
    C.print();
    C = C.transpose();
    C.print();
    B = C.deep_copy();
    cout << (A == B) << endl;
    cout << (B == C) << endl;
    
}