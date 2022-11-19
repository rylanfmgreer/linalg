// machine_learning.hpp
// author: rgreer
// pure abstract class for machine learning

#include "doublevec.hpp"
#include "matrix.hpp"

class MachineLearning
{
    public:
    virtual MachineLearning() = 0;
    virtual void fit();
    // not clear what output predict should have -- doublevec or matrix?

};