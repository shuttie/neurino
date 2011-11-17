#ifndef THRESHOLDFUNCTION_H
#define THRESHOLDFUNCTION_H

#include "function.h"
#include <limits>
//! Threshold activation function.
/*!
  A step function. It's value equals 0 if x<0 and 1 otherwise.
  Derivative value of this function is not smooth (actually is't INF in 0),
  so it's not suitable for learning algorithms like gradient descent.
  */
class ThresholdFunction : public Function
{
public:
    ThresholdFunction(float steepness = DEFAULT_STEEPNESS);
    virtual float value(float x);
    virtual float derivative(float x);
};

#endif // THRESHOLDFUNCTION_H
