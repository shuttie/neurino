#ifndef LINK_H
#define LINK_H

#include "neuron.h"
#include <cstdlib>

class Neuron;

//! Link class.
/*!
  Class which stores pointers to source and destination neuron, link weight and some other link-specific
  variables.
  */
class Link {
public:
    //! Source neuron.
    Neuron* from;
    //! Destination neuron.
    Neuron* to;
    //! Constructor with custom link weight.
    Link(Neuron* from, Neuron *to, float weight);
    //! Constructor with random link weight.
    Link(Neuron *from, Neuron *to);
    //! Link weight.
    /*! It can be any float value from (-inf, inf) range.
      */
    float weight;
    //! Link error gradient.
    float gradient;
    //! Previous value of link error gradient.
    float gradientPrev;
    //! Delta value used in RPROP.
    float delta;
    //! Previous delta value used in RPROP.
    float deltaPrev;
    //! Weight change.
    float deltaW;
    //! Previous weight change
    float deltaWPrev;

};

#endif // LINK_H
