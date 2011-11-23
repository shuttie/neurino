#ifndef BPROPBATCHALGO_H
#define BPROPBATCHALGO_H

#include "bpropalgo.h"

//! Backpropagation algorithm with batch learning.
/*!
  To get the best learning accuracy, you should set a correct learn rate,
  which can be different for different tasks. Higher learn rate results in faster
  convergence, but lesser precision. By default, it's equal to 0.6.

  Batch learning means that network weights are updated after the network sees all
  data samples. It's faster and more accurate.
  */

class BPropBatchAlgo: public BPropAlgo {
public:
    BPropBatchAlgo(float learnRate = DEFAULT_BPROP_LEARNRATE);
    virtual void learn(Network *net, NetworkData *data);
protected:
    virtual void updateGradients(Layer* layer);
};

#endif
