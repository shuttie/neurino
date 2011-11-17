#include "elliottsymmfunction.h"

ElliottSymmFunction::ElliottSymmFunction(float steepness)
    :Function(steepness)
{
}

float ElliottSymmFunction::value(float x)
{
    return (x*steepness) / (1.0f + fabs(x*steepness));
}

float ElliottSymmFunction::derivative(float x)
{
    return steepness/((1.0f+fabs(x*steepness))*(1.0f+fabs(x*steepness)));
}
