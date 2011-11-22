#ifndef LINK_H
#define LINK_H

#include "neuron.h"
#include <cstdlib>

class Neuron;

class Link {
public:
    Neuron* from;
    Neuron* to;
    Link(Neuron* from, Neuron *to, float weight);
    Link(Neuron *from, Neuron *to);
    float weight;
    float gradient;
    float gradientPrev;
    float delta;
    float deltaPrev;
    float deltaW;
    float deltaWPrev;

};

#endif // LINK_H
