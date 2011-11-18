#include "outputlayer.h"

OutputLayer::OutputLayer(unsigned int neuronCount, Function* activationFunction)
    :Layer(neuronCount, activationFunction) {
    isOutput = true;
}
