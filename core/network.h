#ifndef NETWORK_H
#define NETWORK_H

#include "link.h"
#include "layers/layer.h"
#include "neuron.h"
#include <vector>
#include <google/dense_hash_map>

using namespace std;

class Network {
public:
    Layer* inputLayer;
    Layer* outputLayer;
    //! A cache used to store each neuron links.
    google::dense_hash_map<Neuron*, vector<Link*> > linksFrom;
    google::dense_hash_map<Neuron*, vector<Link*> > linksTo;
    //! A Link storage.
    /*!
      We're using this type of link storing for processor cache optimization.
      */
    vector<Link> links;

    vector<Layer*> layers;
    Network();
    void appendLayer(Layer* layer);
    void linkLayers(Layer* from, Layer* to);
private:
    void linkNeurons(Neuron* from, Neuron* to);
};

#endif // NETWORK_H
