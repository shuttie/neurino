#ifndef OUTPUTLAYER_H
#define OUTPUTLAYER_H

#include "layer.h"

class OutputLayer: public Layer {
public:
    OutputLayer(unsigned int neuronCount, Function* activationFunction);
};

#endif // LAYER_H
