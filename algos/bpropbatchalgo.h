#ifndef BPROPBATCHALGO_H
#define BPROPBATCHALGO_H

#include "bpropalgo.h"

class BPropBatchAlgo: public BPropAlgo {
public:
    BPropBatchAlgo(float learnRate = DEFAULT_BPROP_LEARNRATE);
    virtual void learn(Network *net, NetworkData *data);
protected:
    virtual void updateGradients(Layer* layer);
};

#endif
