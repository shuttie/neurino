#include "link.h"

Link::Link(Neuron *from, Neuron *to)
    :from(from), to(to) {

}

Link::Link(Neuron *from, Neuron *to, float weight)
    :from(from), to(to), weight(weight) {

}
