#include "neuron.h"

Neuron::Neuron() {
    isInput = false;
    isOutput = false;
}

Neuron::Neuron(bool isInput, bool isOutput)
    :isInput(isInput), isOutput(isOutput) {

}
