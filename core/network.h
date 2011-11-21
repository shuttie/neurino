#ifndef NETWORK_H
#define NETWORK_H

#include "link.h"
#include "layers/layer.h"
#include "neuron.h"
#include <vector>
#include <stdio.h>

using namespace std;

class Network {
public:
    Layer* inputLayer;
    Layer* outputLayer;
    //! A Link storage.
    /*!
      We're using this type of link storing for processor cache optimization.
      */
    vector<Link*> links;

    vector<Layer*> layers;
    Network();
    void appendLayer(Layer* layer);
    void linkLayers(Layer* from, Layer* to);
    vector<float> execute(vector<float> &input);
};

#endif // NETWORK_H
