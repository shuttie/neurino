#include "bpropalgo.h"

BPropAlgo::BPropAlgo(float learnRate)
    :learnRate(learnRate) {

}

void BPropAlgo::learn(Network *net, NetworkData *data) {
    for (unsigned int d=0; d<data->samples.size(); ++d) {
        // update network inputs to match learn data
        net->inputLayer->setInputs(data->samples[d].inputs);

        // forward-propagating network
        for (unsigned int l=0; l<net->layers.size(); ++l)
            net->layers[l]->propagate();

        // back-propagating error
        // for output layer
        updateSigmaOutput(net->layers.back(), data->samples[d].outputs);
        // for other layers
        for (int l=net->layers.size()-2; l>=0; --l)
            updateSigmaHidden(net->layers[l]);
        for (int l=net->layers.size()-1; l>=1; --l)
            updateGradients(net->layers[l]);

        // updating weights
        updateWeights(net);
    }
}

void BPropAlgo::updateSigmaOutput(Layer *layer, vector<float> &idealOutput)
{
    for (unsigned int i=0; i< layer->neurons.size(); ++i) {
        Neuron* n = &layer->neurons[i];
        n->sigma = -1.0f * n->derivative * (n->value - idealOutput[i]);
    }
}

void BPropAlgo::updateSigmaHidden(Layer *layer)
{
    for (int i=0; i<layer->neurons.size(); ++i) {
        Neuron *neuron = &layer->neurons.at(i);
        vector<Link*> *links = &neuron->linksFrom;
        float sum = 0;
        for (int l=0; l<links->size(); ++l) {
            sum += links->at(l)->weight * links->at(l)->to->sigma;
        }
        neuron->sigma = neuron->derivative * sum;
    }
}

void BPropAlgo::updateWeights(Network* net)
{
    for (int l=0; l<net->links.size(); ++l) {
        net->links.at(l)->weight += net->links.at(l)->gradient * learnRate;
    }
}

void BPropAlgo::updateGradients(Layer *layer)
{
    for (int n=0; n<layer->neurons.size(); ++n) {
        Neuron* neuron = &layer->neurons.at(n);
        vector<Link*> *links = &neuron->linksTo;
        for (int j=0; j<links->size(); ++j) {
            links->at(j)->gradient = neuron->sigma * links->at(j)->from->value;
        }
    }
}


