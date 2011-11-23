#ifndef BPROPMALGO_H
#define BPROPMALGO_H

#include "bpropalgo.h"

//! Online backpropagation algorithm with momentum.
/*!
  The algorithm itself is the same as BPropAlgo, but adjusts network weights with
  a glance to previus update value (it's like an inertion in physics). By default,
  momentum value equals to 0.1
  */

class BPropmAlgo : public BPropAlgo {
public:
    float momentum;
    BPropmAlgo(float learnRate = DEFAULT_BPROP_LEARNRATE, float momentum = DEFAULT_BPROPM_MOMENTUM);
protected:
    virtual void updateWeights(Network *net);

};

#endif
