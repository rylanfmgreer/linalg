#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "doublevec.hpp"
#include "../utilities_src/utility_functions.hpp"

using namespace std;

/*
    some of these vector initializations are quite amateurish and I used
    them as a quick band-aid fix.
*/

DoubleVec::DoubleVec()
{
    // Default initialization giving an empty vector.
    vector<double> d;
    data = d;
}

DoubleVec::DoubleVec(int n)
{
    // Initialization giving a vector of length n, all zeroes.
    vector<double> d(n);
    data = d;
}

DoubleVec::DoubleVec(const vector<double> &v)
{
    // Initialization giving a DoubleVec whose vector is
    // a deep copy of the input vec.
    // Why take in a reference to a vector and then not just take that vector directly?
    // Dunno, sorry. I'm not very good at this.

    vector<double> d(v.size());
    copy(v.begin(), v.end(), d.begin());
    data = d;
}

DoubleVec::DoubleVec(const DoubleVec &v)
{
    data = v.deep_copy().data;
}

DoubleVec::DoubleVec(int n, double x)
{
    // This initialization gives an n-dimensional vector containing x n times.
    vector<double> new_vec(n, x);
    data = new_vec;
}

DoubleVec::DoubleVec(double start, double end, double step)
{
    vector<double> data;
    double add(start);
    while (add < end)
    {
        data.push_back(add);
        add += step;
    }
}

using namespace std;

DoubleVec::DoubleVec(const std::string filename, int column_number, int start_row)
{
    fstream csv;
    string line;
    vector<double> v;

    string segment;
    char separator(',');

    csv.open(filename);
    int row_num(0);
    int col_num;
    while (getline(csv, line))
    {
        if (row_num >= start_row)
        {
            stringstream ss(line);
            col_num = 0;
            while (col_num <= column_number)
            {
                getline(ss, segment, separator);
                col_num++;
            }
            v.push_back(stof(segment));
        }
        row_num++;
    }
    csv.close();
    data = v;
}