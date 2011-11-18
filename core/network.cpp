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
            linkNeurons(&from->neurons.at(i), &to->neurons.at(j));
        }
        linkNeurons(to->biasNeuron, &to->neurons.at(j));
    }
}

void Network::linkNeurons(Neuron *from, Neuron *to)
{
    links.push_back(Link(from, to));
    linksFrom[from].push_back(&links.back());
    linksTo[to].push_back(&links.back());
}
