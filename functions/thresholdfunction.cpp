#include "thresholdfunction.h"

ThresholdFunction::ThresholdFunction(float steepness)
    :Function(steepness)
{
}

float ThresholdFunction::value(float x)
{
    if (x>=0)
        return 1.0f;
    else
        return 0.0f;
}

float ThresholdFunction::derivative(float x)
{
    if (x==0)
        return std::numeric_limits<float>::max();
    else
        return 0;

}
