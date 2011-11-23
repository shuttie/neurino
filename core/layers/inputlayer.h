#ifndef INPUTLAYER_H
#define INPUTLAYER_H

#include "layer.h"

//! Input layer.
/*!
  It's just as Layer, but with inputLayer flag set to true.
  */

class InputLayer : public Layer {
public:
    InputLayer(unsigned int neuronCount, Function* activationFunction);
};

#endif // LAYER_H
