#include "bpropalgo.h"

BPropAlgo::BPropAlgo(float learnRate)
    :learnRate(learnRate) {

}

void BPropAlgo::learn(Network *net, NetworkData *data) {
    for (unsigned int j=0; j<data->samples.size(); ++j) {
        // update network inputs to match learn data
        net->inputLayer->setInputs(data->samples[j].inputs);

        // forward-propagating network
        for (unsigned int i=0; i<net->layers.size(); ++i)
            net->layers[i]->propagate();

        // back-propagating error
        // for output layer
        calcSigmaOutput(net->layers.back(), data->samples[j].outputs);
        // for other layers
        for (int i=net->layers.size()-2; i>=0; --i)
            calcSigmaHidden(net->layers[i]);

        // updating weights for non-input layers
        // (because input layer does not have any weights)
        for (unsigned int i=1; i<net->layers.size(); ++i)
            updateWeights(net->layers[i]);
    }
}

void BPropAlgo::calcSigmaOutput(Layer *layer, vector<float> &idealOutput)
{
    for (unsigned int i=0; i< layer->neurons.size(); ++i) {
        Neuron* n = &layer->neurons[i];
        n->sigma = n->derivative*(idealOutput[i] - n->value);
    }
}

void BPropAlgo::calcSigmaHidden(Layer *layer)
{
    for (int i=0; i<layer->neurons.size(); ++i) {
        float sum = 0;
        vector<Link*> *links = &layer->neurons[i].linksFrom;
        for (int j=0; j<links->size(); ++j) {
            sum += links->at(j)->weight * links->at(j)->to->sigma;
        }
        layer->neurons[i].sigma = layer->neurons[i].derivative * sum;
    }
}

void BPropAlgo::updateWeights(Layer *layer)
{
    for (int j=0; j<layer->neurons.size(); ++j) {
        Neuron *n = &layer->neurons[j];
        vector<Link*> *links = &layer->neurons[j].linksTo;
        for (int i=0; i<links->size(); ++i) {
//            float deltaPrev = n->delta;
            n->delta = n->sigma * learnRate * links->at(i)->from->value;
            links->at(i)->weight += n->delta;
        }
    }
    /*
 FList<Link*>* links;
 Neuron* n;
 float oldDelta = 0, delta = 0;
 for (int j=0; j<cluster->neurons.count();++j) {
         n = cluster->neurons.at(j);
         links = cluster->inputs->linksTo(n);
         for (int i=0; i<links->count();++i) {
                 oldDelta = n->rpDelta;
                 n->rpDelta = n->bpSigma * LEARNRATE * links->at(i)->from->value;
                 if (useMomentum)
                         links->at(i)->weight += n->rpDelta + MOMENTUM*oldDelta;
                 else
                         links->at(i)->weight += n->rpDelta;
         }
 }*/
}

