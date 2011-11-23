#ifndef NETWORK_H
#define NETWORK_H

#include "link.h"
#include "layer.h"
#include "neuron.h"
#include <vector>
#include <stdio.h>
#include <ctime>
#include <cstdlib>

using namespace std;

class Network {
public:
    Layer* inputLayer;
    Layer* outputLayer;
    //! A Link storage.
    vector<Link*> links;
    //! A layer storage
    /*!
      Layers stored in order from input to output.
      */
    vector<Layer*> layers;
    Network();
    ~Network();
    //! Add a layer no the network.
    void appendLayer(Layer* layer);
    //! Link two layers.
    void linkLayers(Layer* from, Layer* to);
    //! Forward-propagate a whole network
    /*!
      This method runs the network and produces output values
      for custom inputs.
      */
    vector<float> execute(vector<float> &input);
};

#endif // NETWORK_H
