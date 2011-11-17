#include "linearfunction.h"

LinearFunction::LinearFunction(float steepness)
    :Function(steepness)
{
}

float LinearFunction::value(float x)
{
    return x*steepness;
}

float LinearFunction::derivative(float x)
{
    return steepness;
}
