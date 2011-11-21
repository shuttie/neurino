#ifndef FUNCTION_H
#define FUNCTION_H

#include "neurino-config.h"
#include <math.h>

//! Base class for different activation function types.
/*!
  If you want to implement a new activation function, remember that
  the function itself must have a derivative.

  Also function performance has a very large impact on the whole network
  perfomance, so keep in mind not to use ineffective math functions like exp() or pow().
  */
class Function
{
public:
    //! Default constructor
    /*!
      \param steepness a float value which manages function smoothness.
      */
    Function(float steepness = DEFAULT_STEEPNESS);
    //! Calculates function value in point x
    /*!
      \param x a point where function value should be calculated.
      */
    virtual float value(float x) = 0;
    //! Calculates function derivative in point x
    /*!
      Remember that the function derivative should be smooth. And it shouldn't have
      any gaps on the whole domain of definition.
      \param x a point where function derivative should be calculated.
      */
    virtual float derivative(float x) = 0;
protected:
    float steepness;
};

#endif // FUNCTION_H
