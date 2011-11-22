#include "bpropbatchalgo.h"

BPropBatchAlgo::BPropBatchAlgo(float learnRate)
    :BPropAlgo(learnRate) {

}

void BPropBatchAlgo::learn(Network *net, NetworkData *data)
{
    //resetting gradient
    for (int l=0; l<net->links.size(); ++l) {
        net->links.at(l)->gradient = 0;
    }

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
    }
    // updating weights
    updateWeights(net);

}

void BPropBatchAlgo::updateGradients(Layer *layer)
{
    for (int n=0; n<layer->neurons.size(); ++n) {
        Neuron* neuron = &layer->neurons.at(n);
        vector<Link*> *links = &neuron->linksTo;
        for (int j=0; j<links->size(); ++j)
            links->at(j)->gradient += neuron->sigma * links->at(j)->from->value;
    }
}
