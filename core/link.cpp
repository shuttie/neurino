#include "link.h"

Link::Link(Neuron *from, Neuron *to)
    :from(from), to(to) {
    weight = (float)rand()/(float)RAND_MAX;
    delta = 0.1f;
    deltaW = 0;
    deltaWPrev = 0;
    gradient = 0;
    gradientPrev = 0;
}

Link::Link(Neuron *from, Neuron *to, float weight)
    :from(from), to(to), weight(weight) {
    delta = 0.1f;
    deltaW = 0;
    deltaWPrev = 0;
    gradient = 0;
    gradientPrev = 0;
}
