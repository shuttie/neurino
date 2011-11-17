#include "tanhfunction.h"

TanhFunction::TanhFunction(float steepness)
    :Function(steepness)
{
}

float TanhFunction::value(float x)
{
    return tanh(steepness*x);
}

float TanhFunction::derivative(float x)
{
    float y = value(x);
    return steepness*(1-(y*y));
}
