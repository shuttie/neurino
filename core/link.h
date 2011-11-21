#ifndef LINK_H
#define LINK_H

#include "neuron.h"

class Neuron;

class Link {
public:
    Neuron* from;
    Neuron* to;
    Link(Neuron* from, Neuron *to, float weight);
    Link(Neuron *from, Neuron *to);
    float weight;
    /*float rpGradient;
    float rpGradientPrev;
    float rpDelta;
    float rpDeltaPrev;
    float rpDeltaW;
    float rpDeltaWPrev;*/

};

#endif // LINK_H
