#ifndef ELLIOTTFUNCTION_H
#define ELLIOTTFUNCTION_H

#include "function.h"


//! Elliott activation function.
/*!
  A fast interpolation of tanh function without exp().
  This function is defined on range (0,1). If you need (-1,1), use ElliottSymmetric.

  More info about this funtion here: http://www.heatonresearch.com/wiki/Elliott_Activation_Function
  */
class ElliottFunction : public Function
{
public:
    ElliottFunction(float steepness = DEFAULT_STEEPNESS);
    virtual float value(float x);
    virtual float derivative(float x);
};

#endif // ELLIOTFUNCTION_H
