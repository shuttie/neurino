#ifndef OUTPUTLAYER_H
#define OUTPUTLAYER_H

#include "layer.h"

//! Output layer.
/*!
  It's just as Layer, but with outputLayer flag set to true.
  */

class OutputLayer: public Layer {
public:
    OutputLayer(unsigned int neuronCount, Function* activationFunction);
};

#endif // LAYER_H
