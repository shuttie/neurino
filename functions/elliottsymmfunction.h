#ifndef ELLIOTTSYMMFUNCTION_H
#define ELLIOTTSYMMFUNCTION_H

#include "function.h"

class ElliottSymmFunction : public Function
{
public:
    ElliottSymmFunction(float steepness = DEFAULT_STEEPNESS);
    virtual float value(float x);
    virtual float derivative(float x);
};

#endif // ELLIOTSYMMFUNCTION_H
