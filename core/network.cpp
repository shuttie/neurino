#include "network.h"

Network::Network() {
}

void Network::appendLayer(Layer *layer)
{
    layers.push_back(layer);
    if (layer->isInput)
        inputLayer = layer;
    if (layer->isOutput)
        outputLayer = layer;
}

void Network::linkLayers(Layer *from, Layer *to)
{
    for (unsigned int j=0; j<to->neurons.size(); ++j) {
        for (unsigned int i=0; i<from->neurons.size(); ++i) {
            // linking neurons
            links.push_back(Link(&from->neurons.at(i), &to->neurons.at(j)));
            from->linksFrom[&from->neurons.at(i)].push_back(&links.back());
            to->linksTo[&to->neurons.at(j)].push_back(&links.back());
        }
        // linking bias
        links.push_back(Link(&to->biasNeuron, &to->neurons.at(j)));
        to->linksTo[&to->neurons.at(j)].push_back(&links.back());
    }
}

vector<float> Network::execute(vector<float> &input)
{
    vector<float> result;
    inputLayer->setInputs(input);
    for (unsigned int i=0; i<layers.size(); ++i) {
        layers.at(i)->propagate();
    }
    for (unsigned int i=0; i<outputLayer->neurons.size(); ++i) {
        result.push_back(outputLayer->neurons[i].value);
    }
    return result;
}
