#include "sigmoidfunction.h"

SigmoidFunction::SigmoidFunction(float steepness)
    :Function(steepness)
{
}

float SigmoidFunction::value(float x)
{
    return 1.0f/(1.0f + exp(-2.0f*steepness*x));
}

float SigmoidFunction::derivative(float x)
{
    float val = value(x);
    return 2.0f*steepness*val*(1.0f - val);
}
