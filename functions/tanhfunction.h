#ifndef TANHFUNCTION_H
#define TANHFUNCTION_H

#include "function.h"

//! Hyperbolic tangent activation function.
/*!
  The hyperbolic tangent activation function (TANH) activation function is a common
  activation function for neural networks. The hyperbolic tangent function will produce
  positive numbers between -1 and 1. The hyperbolic tangent activation function is most
  useful for training data that is also between 0 and 1. Because the hyperbolic tangent
  activation function has a derivative, it can be used with gradient descent based training
  methods. The hyperbolic tangent activation function is perhaps the most common activation
  function used for neural networks.

  The hyperbolic tangent function is a common trigonometric function. However, the use of
  the hyperbolic tangent function in neural networks has little to do with trigonometry.
  The hyperbolic tangent activation function is popular with neural networks because of the
  shape of its graph. The hyperbolic tangent function provides similar scaling to the sigmoid
  activation function, however, the hyperbolic tangent activation function has a range from -1 to 1.
  Because of this greater numeric range the hyperbolic activation function is often used in place
  of the sigmoid activation function.

  More info about this type of fuction is here: http://www.heatonresearch.com/wiki/Hyperbolic_Tangent_Activation_Function
  */
class TanhFunction : public Function
{
public:
    TanhFunction(float steepness = DEFAULT_STEEPNESS);
    virtual float value(float x);
    virtual float derivative(float x);
};

#endif // TANHFUNCTION_H
