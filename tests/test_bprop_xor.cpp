// Test to check BPropAlgo class usability.

#include "neurino.h"
#include <stdio.h>
#include <vector>

using namespace std;

void dump_links(Network* net) {
    printf("whole network:\n");
    for (int i=0; i<net->links.size(); ++i) {
        printf("%X - %X - %f\n", (unsigned int)net->links[i]->from, (unsigned int)net->links[i]->to, net->links[i]->weight);
    }
}

void dump_neurons(Layer* layer) {
    printf("layer:\n");
    for (int i=0; i<layer->neurons.size(); ++i) {
        for (int j=0; j<layer->neurons[i].linksFrom.size(); ++j)
            printf("%X - %X - %f\n", (unsigned int)layer->neurons[i].linksFrom[j]->from, (unsigned int)layer->neurons[i].linksFrom[j]->to, layer->neurons[i].linksFrom[j]->weight);
        for (int j=0; j<layer->neurons[i].linksTo.size(); ++j)
            printf("%X - %X - %f\n", (unsigned int)layer->neurons[i].linksTo[j]->from, (unsigned int)layer->neurons[i].linksTo[j]->to, layer->neurons[i].linksTo[j]->weight);
    }
}

int main(int argc, char** argv) {
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

    NetworkDataArray data(2, 1, dataInput, dataOutput);
    Layer* layer1 = new InputLayer(2, new ElliottFunction());
    Layer* layer2 = new Layer(6, new ElliottFunction());
    Layer* layer3 = new OutputLayer(1, new ElliottFunction());

    Network net;
    //dump_links(&net);
    net.appendLayer(layer1);
    net.appendLayer(layer2);
    net.appendLayer(layer3);
    net.linkLayers(layer1, layer2);
    net.linkLayers(layer2, layer3);
    dump_links(&net);
    dump_neurons(layer1);
    dump_neurons(layer2);
    dump_neurons(layer3);

    BPropAlgo algo;
    ErrorMSE error;
    for (int i=0; i< 100000; ++i) {
        algo.learn(&net, &data);
        if (i % 500 == 0)
            printf("%d - %f\n", i, error.calculate(&net, &data));
    }

}
