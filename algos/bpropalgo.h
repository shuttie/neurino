#ifndef BPROPALGO_H
#define BPROPALGO_H

#include "algo.h"

//! Backpropagation algorithm with online learning.
/*!
  To get the best learning accuracy, you should set a correct learn rate,
  which can be different for different tasks. Higher learn rate results in faster
  convergence, but lesser precision. By default, it's equal to 0.6.

  Online learning means that network weights are updated after each data sample.
  This way is simple, but not very fast and results in less precision.
  */

class BPropAlgo: public Algo {
public:
    //! Algo learn rate.
    float learnRate;
    BPropAlgo(float learnRate = DEFAULT_BPROP_LEARNRATE);
    //! Learning function.
    /*!
      Makes a single iteration of the algorithm.
      */
    virtual void learn(Network *net, NetworkData *data);
protected:
    void updateSigmaOutput(Layer* layer, vector<float> &idealOutput);
    void updateSigmaHidden(Layer* layer);
    virtual void updateGradients(Layer* layer);
    virtual void updateWeights(Network* net);
private:
};

#endif
