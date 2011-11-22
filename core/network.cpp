#include "network.h"

Network::Network() {
    srand(time(NULL));
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
    /*for (int i=0; i<from->neurons.size(); ++i) {
        for (int j=0; j<to->neurons.size(); ++j) {
            //links.push_back(Link(&from->neurons[i], &to->neurons[j]));
            Link *l = new Link(&from->neurons[i], &to->neurons[j]);
            links.push_back(l);
            from->neurons[i].linksFrom.push_back(l);
            to->neurons[j].linksTo.push_back(l);
            printf("linking %X - %X - %f\n", (unsigned int)l->from, (unsigned int)l->to, l->weight);
        }
    }*/
    for (unsigned int j=0; j<to->neurons.size(); ++j) {
        for (unsigned int i=0; i<from->neurons.size(); ++i) {
            // linking neurons
            Link *l = new Link(&from->neurons[i], &to->neurons[j]);
            links.push_back(l);
            to->neurons[j].linksTo.push_back(l);
            from->neurons[i].linksFrom.push_back(l);
        }
        // linking bias
        Link* l2 = new Link(&to->biasNeuron, &to->neurons[j]);
        links.push_back(l2);
        to->neurons[j].linksTo.push_back(l2);
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
