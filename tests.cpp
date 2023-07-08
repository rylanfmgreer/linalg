#include <iostream>
#include <cmath>
#include "all_headers.hpp"
#include <iostream>

using namespace std;

/*
    Testing file for linear algebra pack
    These are quite simple and should provide a
    decent gut check, although not an especially
    thorough review.
*/

// Test 1: addition of two vectors
bool test1()
{
    DoubleVec a(2);
    DoubleVec b(2);
    DoubleVec c(2);

    a[0] = 5;
    a[1] = 15;

    b[0] = 2;
    b[1] = 1;

    c[0] = 7;
    c[1] = 16;
    return ((a + b) == c);
}

// Test 2: Scalar multiplication of a vector
bool test2()
{
    DoubleVec a(2);
    DoubleVec b(2);

    a[0] = 5;
    a[1] = 15;

    b[0] = 1;
    b[1] = 3;

    return (5 * b == a) && (b * 5 == a);
}

// Test 3: concatenation of two vectors
bool test3()
{
    DoubleVec a(2);
    DoubleVec b(2);
    DoubleVec c(4);

    a[0] = 5;
    a[1] = 15;

    b[0] = 1;
    b[1] = 3;

    c[0] = 5;
    c[1] = 15;
    c[2] = 1;
    c[3] = 3;

    return (a.concat(b) == c);
}

// Test 4: dot product of two vectors
bool test4()
{
    DoubleVec a(2);
    DoubleVec b(2);
    a[0] = 5;
    a[1] = 15;

    b[0] = 1;
    b[1] = 3;
    return (a * b == 50.);
}

// Test 5: subtraction of two vectors
bool test5()
{
    DoubleVec a(2);
    DoubleVec b(2);
    DoubleVec c(2);

    a[0] = 5;
    a[1] = 15;

    b[0] = 2;
    b[1] = 1;

    c[0] = 3;
    c[1] = 14;
    return ((a - b) == c);
}

// Test 6: elementwise product of two vectors
bool test6()
{
    DoubleVec a(2);
    DoubleVec b(2);
    DoubleVec c(2);

    a[0] = 5;
    a[1] = 15;

    b[0] = 2;
    b[1] = 1;

    c[0] = 10;
    c[1] = 15;
    return ((a.elementwise(b)) == c);
}

// Test 7: vector contains element
bool test7()
{
    DoubleVec a(3);
    a[0] = 99;
    a[1] = 6;
    a[2] = 3;

    if (a.is_in(98))
        return false;
    return a.is_in(6);
}

// Test 8: Scalar addition to vector
bool test8()
{
    DoubleVec a(2);
    DoubleVec b(2);

    a[0] = 5;
    a[1] = 15;

    b[0] = 7;
    b[1] = 17;

    return (a + 2 == b) && (2 + a == b);
}

// Test 9: Deep copy
bool test9()
{
    DoubleVec a(2);
    DoubleVec b(2);

    a[0] = 5;
    a[1] = 15;
    b = a.deep_copy();
    b[1] = 999;

    return (a[1] == 15) && (b[1] == 999);
}

// Test 10: Apply
double test_10_f(double x) { return x * x; } // square function just for this test
bool test10()
{
    DoubleVec a(2);
    DoubleVec b(2);

    a[0] = 5;
    a[1] = 15;
    b = a.apply(test_10_f);
    return (a[0] == 5) && (b[0] == 25);
}

// Test 11: push_back
bool test11()
{
    DoubleVec a(2);
    a.push_back(3);
    return (a[2] == 3);
}

// Test 12: get
bool test12()
{
    DoubleVec a(2);
    a[0] = 15;
    a[1] = 2;

    double v(a.get(1));
    double w(a[1]);
    w = 1000;
    return (a[1] == 2) && (v == 2) && (w == 1000);
}

// Test 13: sum
double stat_test_f(double x) { return x * x; }
bool test13()
{
    DoubleVec a(3);
    DoubleVec b(3);
    for (int i(0); i < a.size(); ++i)
    {
        a[i] = i + 1;
        b[i] = stat_test_f(i + 1);
    }
    return (a.sum() == 6);
}

// Test 14: mean
bool test14()
{
    DoubleVec a(3);
    DoubleVec b(3);
    for (int i(0); i < a.size(); ++i)
    {
        a[i] = i + 1;
        b[i] = stat_test_f(i + 1);
    }
    return (a.mean() == 2);
}

// Test 15: var
bool test15()
{
    DoubleVec a(3);
    DoubleVec b(3);
    for (int i(0); i < a.size(); ++i)
    {
        a[i] = i + 1;
        b[i] = stat_test_f(i + 1);
    }
    return (a.var() == 2. / 3.);
}

// Test 16: std
bool test16()
{
    DoubleVec a(3);
    DoubleVec b(3);
    for (int i(0); i < a.size(); ++i)
    {
        a[i] = i + 1;
        b[i] = stat_test_f(i + 1);
    }
    return (a.stdev() == sqrt(2. / 3.));
}

// Test 17: cov
bool test17()
{
    DoubleVec a(3);
    DoubleVec b(3);
    for (int i(0); i < a.size(); ++i)
    {
        a[i] = i + 1;
        b[i] = stat_test_f(i + 1);
    }
    return (abs(a.cov(b) - 2.6666666666666) < 1e-8);
}

// Test 18: cor
bool test18()
{
    DoubleVec a(3);
    DoubleVec b(3);
    for (int i(0); i < a.size(); ++i)
    {
        a[i] = i + 1;
        b[i] = stat_test_f(i + 1);
    }
    return (abs(a.cor(b) - 0.98974332) < 1e-8);
}

// Test 19: zero matrix
bool test19()
{
    Matrix A(2, 2);
    return A == (0 * A);
}

// Test 20: add a scalar
bool test20()
{
    Matrix A(2);
    A = A + 5;
    return A(0, 0) == 6;
}

// Test 21: subtract a scalar
bool test21()
{
    Matrix A(2);
    A = A - 5;
    return A(0, 0) == -4;
}

// Test 22: deep copy
bool test22()
{
    Matrix A(2);
    A(0, 1) = 99;
    Matrix B;
    B = A.deep_copy();
    A(1, 0) = 12;
    B(1, 1) = 500;

    return (A(1, 1) == 1) && (B(1, 0) == 0) && (B(0, 1) == 99);
}

// Test 23: Transpose
bool test23()
{
    Matrix M(2, 3);
    M(1, 2) = 99;
    Matrix N = M.transpose();
    N(0, 0) = 12093;
    return (N(2, 1) == 99) && (M(0, 0) == 0);
}

// Test 24: wide matrix
bool test24()
{
    // set up vectors of ones
    DoubleVec v(3);
    DoubleVec w(4);
    v = v + 1;
    w = w + 1;

    // set up long and wide matrix
    Matrix A(v);
    Matrix B(w);
    B = B.transpose();

    // A: 3 x 1
    // B: 1 x 4
    // A x B -> 3 x 4
    Matrix C = A * B;
    Matrix D(3, 4);
    D = D + 1;
    return C == D;
}

// Test 25: drop row
bool test25()
{
    // set up vectors of ones
    DoubleVec v(3);
    DoubleVec w(4);
    v = v + 1;
    w = w + 1;

    // set up long and wide matrix
    Matrix A(v);
    Matrix B(w);
    B = B.transpose();

    // A: 3 x 1
    // B: 1 x 4
    // A x B -> 3 x 4
    Matrix C = A * B;
    C = C.drop_row(1);
    Matrix D(2, 4);
    D = D + 1;
    return C == D;
}

// Test 26: drop col
bool test26()
{
    // set up vectors of ones
    DoubleVec v(3);
    DoubleVec w(4);
    v = v + 1;
    w = w + 1;

    // set up long and wide matrix
    Matrix A(v);
    Matrix B(w);
    B = B.transpose();

    // A: 3 x 1
    // B: 1 x 4
    // A x B -> 3 x 4
    Matrix C = A * B;
    C = C.drop_col(1);
    Matrix D(3, 3);
    D = D + 1;
    return C == D;
}

// Test 27: determinant
bool test27()
{
    // set up matrix
    int n(2);
    Matrix A(n, n);
    for (int r(0); r < n; ++r)
    {
        for (int c(0); c < n; ++c)
        {
            A(r, c) = r * n + c + 1;
        }
    }
    return util::close(A.determinant(), -2.);
}

// Test 28: determinant test 2
bool test28()
{
    Matrix A(4, 4);
    DoubleVec v(4);
    for (int i(0); i < 4; ++i)
    {
        v[i] = i + 1.;
    }
    A[0] = v;
    A[1] = v.elementwise(v);
    A[2] = v.elementwise(v).elementwise(v);
    A[3] = v.elementwise(v).elementwise(v).elementwise(v);
    return util::close(A.determinant(), 288.);
}

// Test 29: swap rows
bool test29()
{
    Matrix A(3);
    A.swap_rows(1, 2);
    DoubleVec calc_vec = A.row(1);
    DoubleVec test_vec(3);
    test_vec[2] = 1;
    return calc_vec == test_vec;
}

// Test 30: RREF. basic
bool test30()
{
    Matrix A(2, 3);
    Matrix B(2, 3);
    Matrix test(2, 3);
    test(0, 0) = 1;
    test(1, 1) = 1;
    test(0, 2) = 1;
    test(1, 2) = 2. / 3.;

    A[0][0] = 1;
    A[0][1] = 2;
    A[1][1] = 3;
    A[2][0] = 1;
    A[2][1] = 4;
    B = rref(A);
    return (B == test);
}

// Test 31: RREF. swap to get pivot
bool test31()
{
    Matrix A(2, 3);
    Matrix B(2, 3);
    Matrix test(2, 3);
    test(0, 1) = 1.;
    A(1, 1) = 1.;
    B = rref(A);
    return (B == test);
}

// Test 32: inverse, simple
bool test32()
{
    Matrix A(2, 2); // A is test
    A(0, 0) = -2;
    A(0, 1) = 1;
    A(1, 0) = 1.5;
    A(1, 1) = -0.5;

    Matrix B(2, 2);
    B(0, 0) = 1;
    B(0, 1) = 2;
    B(1, 0) = 3;
    B(1, 1) = 4;

    Matrix C = inv(B);
    return (C == A);
}

// Test 33: inverse, larger
bool test33()
{
    Matrix A(4, 4);
    for (int i(0); i < 4; ++i)
    {
        for (int j(0); j < 4; ++j)
        {
            A(j, i) = pow((i + 1), j);
        }
    }
    Matrix test(4, 4);
    test(0, 0) = 4;
    test(0, 1) = -13. / 3.;
    test(0, 2) = 1.5;
    test(0, 3) = -1. / 6.;

    test(1, 0) = -6;
    test(1, 1) = 9.5;
    test(1, 2) = -4;
    test(1, 3) = 1. / 2.;

    test(2, 0) = 4;
    test(2, 1) = -7;
    test(2, 2) = 3.5;
    test(2, 3) = -0.5;

    test(3, 0) = -1;
    test(3, 1) = 11. / 6.;
    test(3, 2) = -1;
    test(3, 3) = 1. / 6.;
    return (inv(A) == test);
}

// test 34: simple equation solver
bool test34()
{
    Matrix A(2, 2);
    A(0, 0) = 1;
    A(0, 1) = 2;
    A(1, 0) = 3;
    A(1, 1) = 4;

    DoubleVec v(2);
    v[0] = 3.5;
    v[1] = 8.5;

    DoubleVec w = inv(A) * v;
    DoubleVec z(2);
    z[0] = 1.5;
    z[1] = 1;

    return (w == z);
}

bool test35()
{
    Matrix A(2, 3);
    A(0, 0) = 1;
    A(0, 1) = 2;
    A(1, 0) = 3;
    A(1, 1) = 4;
    A(1, 2) = 5;

    Matrix B = nullspace(A);
    Matrix C = A * B;
    DoubleVec Z(2);
    return C == Z;
}

// cumsum
bool test36()
{

    int n(10);
    std::vector<double> v(n);
    std::vector<double> w(n);
    v[0] = w[0] = 0;
    for (int i(1); i < n; ++i)
    {
        v[i] = i;
        w[i] = w[i - 1] + i;
    }
    DoubleVec v_1(v);
    DoubleVec w_1(w);
    return v_1.cumsum() == w_1;
}

// parameterized_function
DoubleVec option_payoff(DoubleVec x, DoubleVec k)
{
    std::vector<double> ret_vec(x.size());
    std::transform(x.begin(), x.end(), k.begin(),
                   ret_vec.begin(), [](double x_, double k_)
                   { return std::max(x_ - k_, 0.); });
    return DoubleVec(ret_vec);
}

// parameterized function test
bool test37()
{
    DoubleVec k;
    k.push_back(2);

    DoubleVec x;
    x.push_back(5);
    DoubleVec x_result;
    x_result.push_back(3);

    DoubleVec y;
    y.push_back(1);
    DoubleVec y_result;
    y_result.push_back(0);

    ParameterizedFunction pf(option_payoff, k);
    DoubleVec z_1 = pf(x);
    DoubleVec z_2 = pf(y);

    if (z_1 != x_result)
        return false;
    return z_2 == y_result;
}

// parameterized function test -- 1d
bool test38()
{
    DoubleVec k;
    k.push_back(2);

    DoubleVec x;
    x.push_back(5);
    DoubleVec x_result;
    x_result.push_back(3);

    DoubleVec y;
    y.push_back(1);
    DoubleVec y_result;
    y_result.push_back(0);

    ParameterizedFunction pf(option_payoff, k);
    double z_1 = pf.x_variable_W_constant_1d(x);
    double z_2 = pf.x_variable_W_constant_1d(y);

    if (z_1 != x_result[0])
        return false;
    return z_2 == y_result[0];
}

// complex addition
bool test39()
{
    Complex z(1, 2);
    Complex w(3, 4);
    Complex x(4, 6);
    return (z + w) == x;
}

// complex angle
bool test40()
{
    Complex z(0, 1);
    return z.angle() == (M_PI / 2);
}

// a few complex tasks...
bool test41()
{
    Complex z(1, 1);
    double r = sqrt(2);
    assert(z.magnitude() == r);

    Complex w = z + 1.;
    return w.m_re == 2.;
}

// inverting a complex number
bool test42()
{
    Complex z(12, 320);
    Complex w = z * z.inverse();
    return (z * z.inverse()) == 1.;
}

// ndarray stuff
bool test43()
{
    std::vector<unsigned int> v{4, 5, 2, 1, 0, 9};
    std::vector<unsigned int> res{2, 1, 3, 4, 5, 0};
    std::vector<unsigned int> calc = util::argsort(v);
    for (int i(0); i < v.size(); ++i)
    {
        // assert( calc[i] == res[i] );
    }
    return true;
}

// kmeans stuff
bool test44()
{
    int n_means = 3;
    int n_iterations_per_round = 10;
    int n_rounds = 10;
    KMeans model(n_means = n_means, n_rounds = n_rounds, n_iterations_per_round = n_iterations_per_round);

    int n_obs = 100;
    int n_dim = 2;
    Matrix X(n_obs, n_dim);
    for (int r(0); r < n_obs; ++r)
    {
        for (int c(0); c < n_dim; ++c)
        {
            double r_mean = r % 3;
            double c_mean = r_mean;
            X(r, c) = r_mean + 0.3 * util::crude_normal_rv();
        }
    }
    model.fit(X);
    DoubleVec v = model.predict(X);
    return true;
}

bool test45()
{
    std::string filename = "rands_2.csv";
    Matrix X(filename);
    int n_means = 3;
    int n_iterations_per_round = 10;
    int n_rounds = 10;
    KMeans  model(n_means = n_means, n_rounds = n_rounds, n_iterations_per_round = n_iterations_per_round);
    model.fit(X);
    DoubleVec predictions = model.predict(X);
    predictions.print();
    return false;

}

bool test46()
{
    std::string filename = "test_data/two_d_rands.csv";
    Matrix X(filename);
    DoubleVec y(X.nrow());
    y[0] = 0.; // just in case...
    std::transform(y.m_data.begin(), y.m_data.end() - 1,
                   y.m_data.begin() + 1, [](double x){ return x + 1.; });

    WeightedAvgRegression war(WeightFunc::equal_weights);
    war.fit(X, y);
    DoubleVec yhat = war.predict(X);

    bool test_succeded = true;
    double first_view = yhat.get(0);
    std::for_each(yhat.begin(), yhat.end(),
        [&test_succeded, first_view]( double x )
        { if(x != first_view) test_succeded = false; });
    return test_succeded;

}

bool test47()
{
    RidgeRegression R0(0.);
    RidgeRegression R1(1.);
    LinearRegression L;

    Matrix data("test_data/two_d_rands.csv");
    Matrix X = data.drop_col(1);
    DoubleVec y = data.col(1);

    R0.fit(X, y);
    R1.fit(X, y);
    L.fit(X, y);

    DoubleVec yhr0 = R0.predict(X);
    DoubleVec yhr1 = R1.predict(X);
    DoubleVec yhr  = L.predict(X);

    if(yhr0 == yhr1)
        return false;
    if(yhr0 != yhr)
        return false;
    return true;    
}

bool test48()
{
    // NOT COMPLETE
    DoubleVec dv(100, 1.);
    dv = dv.cumsum();
    DoubleVec rs = dv.rolling_sum(6, 3);

    return false;
}

bool test49()
{
    // incomplete, just sees whether we can actually
    // fit at all!!
    Matrix X(10, 1);
    DoubleVec y(10);
    Lowess Model(0.2);

    for( int i(0); i < 10; ++i)
    {
        X(i, 0) = i;
        y[i] = i * i;
    }

    Model.fit(X, y);
}

int main()
{
    cout << endl
         << endl;
    cout << "TESTS PASSED:";
    cout << endl
         << boolalpha;
    cout << " Test   1 results:   " << test1() << endl;
    cout << " Test   2 results:   " << test2() << endl;
    cout << " Test   3 results:   " << test3() << endl;
    cout << " Test   4 results:   " << test4() << endl;
    cout << " Test   5 results:   " << test5() << endl;
    cout << " Test   6 results:   " << test6() << endl;
    cout << " Test   7 results:   " << test7() << endl;
    cout << " Test   8 results:   " << test8() << endl;
    cout << " Test   9 results:   " << test9() << endl;
    cout << " Test  10 results:   " << test10() << endl;
    cout << " Test  11 results:   " << test11() << endl;
    cout << " Test  12 results:   " << test12() << endl;
    cout << " Test  13 results:   " << test13() << endl;
    cout << " Test  14 results:   " << test14() << endl;
    cout << " Test  15 results:   " << test15() << endl;
    cout << " Test  16 results:   " << test16() << endl;
    cout << " Test  17 results:   " << test17() << endl;
    cout << " Test  18 results:   " << test18() << endl;
    cout << " Test  19 results:   " << test19() << endl;
    cout << " Test  20 results:   " << test20() << endl;
    cout << " Test  21 results:   " << test21() << endl;
    cout << " Test  22 results:   " << test22() << endl;
    cout << " Test  23 results:   " << test23() << endl;
    cout << " Test  24 results:   " << test24() << endl;
    cout << " Test  25 results:   " << test25() << endl;
    cout << " Test  26 results:   " << test26() << endl;
    cout << " Test  27 results:   " << test27() << endl;
    cout << " Test  28 results:   " << test28() << endl;
    cout << " Test  29 results:   " << test29() << endl;
    cout << " Test  30 results:   " << test30() << endl;
    cout << " Test  31 results:   " << test31() << endl;
    cout << " Test  32 results:   " << test32() << endl;
    cout << " Test  33 results:   " << test33() << endl;
    cout << " Test  34 results:   " << test34() << endl;
    cout << " Test  35 results:   " << test35() << endl;
    cout << " Test  36 results:   " << test36() << endl;
    cout << " Test  37 results:   " << test37() << endl;
    cout << " Test  38 results:   " << test38() << endl;
    cout << " Test  39 results    " << test39() << endl;
    cout << " Test  40 results    " << test40() << endl;
    cout << " Test  41 results    " << test41() << endl;
    cout << " Test  42 results    " << test42() << endl;
    cout << " Test  43 results    " << test43() << endl;
    cout << " Test  44 results    " << test44() << endl;
    cout << " Test  45 results    " << test45() << endl;
    cout << " Test  46 results    " << test46() << endl;
    cout << " Test  47 results    " << test47() << endl;
    cout << " Test  48 results    " << test48() << endl;
    cout << endl;
}