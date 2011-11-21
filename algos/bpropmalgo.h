#ifndef BPROPMALGO_H
#define BPROPMALGO_H

#include "bpropalgo.h"

class BPropmAlgo : public BPropAlgo {
public:
    float momentum;
    BPropmAlgo(float learnRate, float momentum);
protected:
    virtual void updateWeights(Layer *layer);

};

#endif
