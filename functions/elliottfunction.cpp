#include "elliottfunction.h"

ElliottFunction::ElliottFunction(float steepness)
    :Function(steepness)
{
}

float ElliottFunction::value(float x)
{
    return (float)((0.5f*(x*steepness) ) / (1.0f + fabs(x*steepness)) + 0.5f);
}

float ElliottFunction::derivative(float x)
{
    return steepness/(2.0f*(1+fabs(x*steepness))*(1.0f+fabs(x*steepness)));
}
