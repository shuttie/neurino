#include "inputlayer.h"

InputLayer::InputLayer(unsigned int neuronCount, Function* activationFunction)
    :Layer(neuronCount, activationFunction) {
    isInput = true;
}
