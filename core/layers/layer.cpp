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

void Layer::propagate()
{
    if (!isInput) {
        for (unsigned int i=0; i<neurons.size(); ++i) {
            vector<Link*> *list = &neurons[i].linksTo;
                    //&(*linksTo)[&neurons.at(i)];
            float sum = 0;
            for (unsigned int j=0; j<list->size(); ++j) {
                sum += list->at(j)->from->value * list->at(j)->weight;
            }
            neurons[i].value = activationFunction->value(sum);
            neurons[i].derivative = activationFunction->derivative(sum);
        }
    }
}
