#ifndef BPROPMALGO_H
#define BPROPMALGO_H

#include "bpropalgo.h"

class BPropmAlgo : public BPropAlgo {
public:
    float momentum;
    BPropmAlgo(float learnRate = DEFAULT_BPROP_LEARNRATE, float momentum = DEFAULT_BPROPM_MOMENTUM);
protected:
    virtual void updateWeights(Network *net);

};

#endif
