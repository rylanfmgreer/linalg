#include "complex_number.hpp"
using namespace std;

Complex horner_polynomial( const vector<Complex> &v, const Complex z )
{
    Complex s = v[0];
    for( int i(1); i < v.size(); ++i )
    {
        s = s * z;
        s = s + v[i];
    }
    return s;
}
