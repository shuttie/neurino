#include "bpropmalgo.h"

BPropmAlgo::BPropmAlgo(float learnRate, float momentum)
    :BPropAlgo(learnRate), momentum(momentum) {

}

void BPropmAlgo::updateWeights(Layer *layer)
{
    for (int j=0; j<layer->neurons.size(); ++j) {
        Neuron *n = &layer->neurons[j];
        vector<Link*> *links = &layer->neurons[j].linksTo;
        for (int i=0; i<links->size(); ++i) {
            float deltaPrev = n->delta;
            n->delta = n->sigma * learnRate * links->at(i)->from->value;
            links->at(i)->weight += n->delta + momentum*deltaPrev;
        }
    }
}
