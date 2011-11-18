// Test to check Network class usability.

#include "core/network.h"
#include "core/layers/inputlayer.h"
#include "core/layers/outputlayer.h"
#include "functions/elliottfunction.h"
#include <stdio.h>

int main(int argc, char** argv) {
    Network net;
    Layer* layer1 = new InputLayer(2, new ElliottFunction());
    Layer* layer2 = new Layer(6, new ElliottFunction());
    Layer* layer3 = new OutputLayer(1, new ElliottFunction());
    net.appendLayer(layer1);
    net.appendLayer(layer2);
    net.appendLayer(layer3);

    net.linkLayers(layer1, layer2);
    net.linkLayers(layer2, layer3);
    if ((net.layers.size() == 3))
        printf("PASS\n");
    else
        printf("FAIL\n");
}
