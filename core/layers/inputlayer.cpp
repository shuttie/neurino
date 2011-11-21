#include "inputlayer.h"

InputLayer::InputLayer(unsigned int neuronCount, Function* activationFunction)
    :Layer(neuronCount, activationFunction) {
    isInput = true;
    for (unsigned int i=0; i<neurons.size(); ++i) {
        neurons[i].isInput = true;
    }
}
