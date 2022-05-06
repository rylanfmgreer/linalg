#include "src/doublevec.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string filename("longitudes.csv");
    DoubleVec longitudes(filename, 1, 0);
    cout << "The average Longitude of our fair friends is: ";
    cout << longitudes.mean() << endl;
}