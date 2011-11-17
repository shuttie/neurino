#ifndef SIGMOIDFUNCTION_H
#define SIGMOIDFUNCTION_H

#include "function.h"
//! Classical sigmoid activation function.
/*!
  The sigmoid activation function is a common activation function for neural networks.
  The sigmoid function will only produce positive numbers between 0 and 1. The sigmoid
  activation function is most useful for training data that is also between 0 and 1.
  Because the sigmoid activation function has a derivative, it can be used with gradient
  descent based training methods.

  More info here: http://www.heatonresearch.com/wiki/Sigmoid

  */
class SigmoidFunction : public Function
{
public:
    SigmoidFunction(float steepness = DEFAULT_STEEPNESS);
    virtual float value(float x);
    virtual float derivative(float x);
};

#endif // SIGMOIDFUNCTION_H
