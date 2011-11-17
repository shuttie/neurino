#include "elliottfunction.h"

ElliotFunction::ElliotFunction(float steepness)
    :Function(steepness)
{
}

float ElliotFunction::value(float x)
{
    return (float)(((x*steepness) / 2) / (1 + fabs(x*steepness)) + 0.5);
}

float ElliotFunction::derivative(float x)
{
    return steepness/(2*(1+ffabs(x*steepness))*(1+fabs(x*steepness)));
}
