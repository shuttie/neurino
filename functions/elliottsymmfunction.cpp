#include "elliotsymmfunction.h"

ElliotSymmFunction::ElliotSymmFunction(float steepness)
    :Function(steepness)
{
}

float ElliotSymmFunction::value(float x)
{
    return (x*steepness) / (1 + ffabs(x*steepness));
}

float ElliotSymmFunction::derivative(float x)
{
    return steepness/((1+ffabs(x*steepness))*(1+ffabs(x*steepness)));
}
