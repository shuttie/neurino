#ifndef ELLIOTTSYMMFUNCTION_H
#define ELLIOTTSYMMFUNCTION_H

#include "function.h"

//! A symmetric Elliott activation function.
/*!
  This function is defined on range (-1,1). If you need (0,1), use plain Elliott.

  More info about this funtion here: http://www.heatonresearch.com/wiki/Elliott_Activation_Function
  */
class ElliottSymmFunction : public Function
{
public:
    ElliottSymmFunction(float steepness = DEFAULT_STEEPNESS);
    virtual float value(float x);
    virtual float derivative(float x);
};

#endif // ELLIOTSYMMFUNCTION_H
