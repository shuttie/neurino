#include "rpropalgo.h"

RPropAlgo::RPropAlgo(float deltaMin, float deltaMax, float nuMinus, float nuPlus)
    : deltaMin(deltaMin), deltaMax(deltaMax), nuMinus(nuMinus), nuPlus(nuPlus) {

}

void RPropAlgo::learn(Network *net, NetworkData *data)
{
    // clearing gradients values
    for (int l=0; l<net->links.size(); ++l) {
        net->links.at(l)->gradient = 0;
    }
    //forward- and back-propagating
    for (int d=0; d<data->samples.size(); ++d) {
        net->inputLayer->setInputs(data->samples[d].inputs);
        for (int l=0; l<net->layers.size(); ++l) {
            net->layers[l]->propagate();
        }
        updateSigmaOutput(net->layers.back(), data->samples[d].outputs);
        for (int l=net->layers.size()-2; l>=0; --l) {
            updateSigmaHidden(net->layers[l]);
        }
        for (int l=net->layers.size()-1; l>=1; --l)
            updateGradients(net->layers[l]);
    }

    // updating weights
    updateAllWeights(net);
}

void RPropAlgo::updateWeights(Layer *layer) {
    /*for (int n=0; n<layer->neurons.size(); ++n) {
        for (int i=0; i<layer->neurons[n].linksTo.size(); ++i) {
            Link *l = layer->neurons[n].linksTo[i];
            float mult = l->gradient * l->gradientPrev;
            if (mult > 0) {
                l->delta = rmin(l->delta * nuPlus, deltaMax);
                l->deltaW = 1.0f*rsign(l->gradient) * l->delta; //-
                l->weight += l->deltaW;
                l->gradientPrev = l->gradient;
            } else if (mult < 0) {
                l->delta = rmax(l->delta * nuMinus, deltaMin);
                l->gradientPrev = 0;
            } else {
                l->deltaW = 1.0f*rsign(l->gradient) * l->delta; //-
                l->weight += l->deltaW;
                //l->gradientPrev = l->gradient;
            }
        }
    }*/
}

void RPropAlgo::updateAllWeights(Network *net)
{
    for (int i=0; i<net->links.size(); ++i) {
        Link *l = net->links[i];
        float mult = l->gradient * l->gradientPrev;
        if (mult > 0) {
            l->delta = fast_min(l->delta * nuPlus, deltaMax);
            l->deltaW = fast_sign(l->gradient) * l->delta; //-
            l->weight += l->deltaW;
            l->gradientPrev = l->gradient;
        } else if (mult < 0) {
            l->delta = fast_max(l->delta * nuMinus, deltaMin);
            //l->weight -= l->deltaW;
            l->gradientPrev = 0;
        } else {
            l->deltaW = fast_sign(l->gradient) * l->delta; //-
            l->weight += l->deltaW;
            l->gradientPrev = l->gradient;
        }
    }
}
