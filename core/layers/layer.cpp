#include "layer.h"

Layer::Layer(unsigned int neuronCount, Function *activationFunction)
    :neuronCount(neuronCount), activationFunction(activationFunction)
{
    isInput = false;
    isOutput = false;
    for (int i=0; i<neuronCount; ++i) {
        neurons.push_back(Neuron(isInput, isOutput));
    }
    biasNeuron.isInput = true;
}

Layer::~Layer() {
    delete activationFunction;
}

void Layer::setInputs(vector<float> &inputs)
{
    for (unsigned int i=0; i<inputs.size(); ++i) {
        neurons.at(i).value = inputs.at(i);
    }
}
