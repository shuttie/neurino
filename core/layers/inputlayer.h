#ifndef INPUTLAYER_H
#define INPUTLAYER_H

#include "layer.h"

class InputLayer : public Layer {
public:
    InputLayer(unsigned int neuronCount, Function* activationFunction);
};

#endif // LAYER_H
