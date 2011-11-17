#ifndef LINEARFUNCTION_H
#define LINEARFUNCTION_H

#include "function.h"

//! Linear activation function
/*!
  Very fast and simple activation function: f(x) = x*steepness.
  The function accuracy is very low, so it's not recommended for any production use.
  */
class LinearFunction : public Function
{
public:
    LinearFunction(float steepness = DEFAULT_STEEPNESS);
    virtual float value(float x);
    virtual float derivative(float x);
};

#endif // LINEARFUNCTION_H
