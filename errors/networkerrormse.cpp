#include "networkerrormse.h"

NetworkErrorMSE::NetworkErrorMSE() {

}

float NetworkErrorMSE::calculate(Network *net, NetworkData *dataset) {
    float err = 0;
    for (unsigned int i=0; i<dataset->samples.size(); ++i) {
        net->inputLayer->setInputs(dataset->samples[i].inputs);
        for (int j=0; j<net->layers.size(); ++j) {
            net->layers.at(j)->propagate();
        }
        for (int j=0; j<net->outputLayer->neurons.size(); ++j) {
            float networkValue = net->outputLayer->neurons[j].value;
            float idealValue = dataset->samples[i].outputs[j];
            err += (networkValue - idealValue)*(networkValue - idealValue);
        }
    }
    return (err/(float)((net->outputLayer->neurons.size()) * dataset->samples.size()));
}
