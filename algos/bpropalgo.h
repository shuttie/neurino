#ifndef BPROPALGO_H
#define BPROPALGO_H

#include "algo.h"

class BPropAlgo: public Algo {
public:
    float learnRate;
    BPropAlgo(float learnRate = DEFAULT_BPROP_LEARNRATE);
    virtual void learn(Network *net, NetworkData *data);
protected:
    void calcSigmaOutput(Layer* layer, vector<float> &idealOutput);
    void calcSigmaHidden(Layer* layer);
    virtual void updateWeights(Layer* layer);
};

#endif
