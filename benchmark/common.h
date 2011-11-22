#ifndef COMMON_H
#define COMMON_H

#include "neurino.h"

inline NetworkData* generate_xor_data() {
    vector<float> xor1in, xor1out, xor2in, xor2out, xor3in, xor3out, xor4in, xor4out;
    xor1in.push_back(0);
    xor1in.push_back(0);
    xor1out.push_back(0);

    xor2in.push_back(0);
    xor2in.push_back(1);
    xor2out.push_back(1);

    xor3in.push_back(1);
    xor3in.push_back(0);
    xor3out.push_back(1);

    xor4in.push_back(1);
    xor4in.push_back(1);
    xor4out.push_back(0);

    vector< vector<float> > dataInput, dataOutput;
    dataInput.push_back(xor1in);
    dataInput.push_back(xor2in);
    dataInput.push_back(xor3in);
    dataInput.push_back(xor4in);

    dataOutput.push_back(xor1out);
    dataOutput.push_back(xor2out);
    dataOutput.push_back(xor3out);
    dataOutput.push_back(xor4out);

    return new NetworkDataArray(2, 1, dataInput, dataOutput);
}

inline Network* generate_xor_network() {
    Layer* layer1 = new InputLayer(2, new ElliottFunction());
    Layer* layer2 = new Layer(6, new ElliottFunction());
    Layer* layer3 = new OutputLayer(1, new ElliottFunction());

    Network *net = new Network();
    net->appendLayer(layer1);
    net->appendLayer(layer2);
    net->appendLayer(layer3);
    net->linkLayers(layer1, layer2);
    net->linkLayers(layer2, layer3);
    return net;

}

#endif
