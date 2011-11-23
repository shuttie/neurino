#ifndef RPROPALGO_H
#define RPROPALGO_H

#include "algo.h"
#include "bpropbatchalgo.h"

//! Classic resilient back-propagation as described in original Riedmiller paper.
/*!
  RPROP algorithm. Much faster and precise than BProp and does not require setting
  appropriate learn rate.
  */

class RPropAlgo : public BPropBatchAlgo {
public:
    float deltaMin, deltaMax;
    float nuMinus, nuPlus;
    RPropAlgo(float deltaMin = DEFAULT_RPROP_DELTAMIN,
              float deltaMax = DEFAULT_RPROP_DELTAMAX,
              float nuMinus  = DEFAULT_RPROP_NUMINUS,
              float nuPlus   = DEFAULT_RPROP_NUPLUS);
    virtual void learn(Network *net, NetworkData *data);
protected:
    virtual void updateWeights(Network* net);
};

#endif
