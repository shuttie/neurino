#ifndef BPROPALGO_H
#define BPROPALGO_H

#include "algo.h"

class BPropAlgo: public Algo {
public:
    float learnRate;
    BPropAlgo(float learnRate = DEFAULT_BPROP_LEARNRATE);
    virtual void learn(Network *net, NetworkData *data);
protected:
    void updateSigmaOutput(Layer* layer, vector<float> &idealOutput);
    void updateSigmaHidden(Layer* layer);
    virtual void updateGradients(Layer* layer);
    virtual void updateWeights(Network* net);
private:
};

#endif
