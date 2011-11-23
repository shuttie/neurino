#ifndef RPROPALGO_H
#define RPROPALGO_H

#include "algo.h"
#include "bpropbatchalgo.h"

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
    virtual void updateWeights(Layer *layer);

private:
    void updateAllWeights(Network* net);
};

#endif
