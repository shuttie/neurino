#ifndef ELLIOTTFUNCTION_H
#define ELLIOTTFUNCTION_H

#include "function.h"

class ElliottFunction : public Function
{
public:
    ElliottFunction(float steepness = DEFAULT_STEEPNESS);
    virtual float value(float x);
    virtual float derivative(float x);
};

#endif // ELLIOTFUNCTION_H
