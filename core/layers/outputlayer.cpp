#include "outputlayer.h"

OutputLayer::OutputLayer(unsigned int neuronCount, Function* activationFunction)
    :Layer(neuronCount, activationFunction) {
    isOutput = true;
    for (unsigned int i=0; i<neurons.size(); ++i) {
        neurons[i].isOutput = true;
    }
}
