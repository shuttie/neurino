#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include "link.h"

using namespace std;

class Link;

//! Simple neuron class.
/*!

  */
class Neuron {
public:
    //! Neuron belongs to network input layer.
    bool isInput;
    //! Neuron belongs to network output layer.
    bool isOutput;
    //! Current neuron output.
    float value;
    //! Current derivative value for neuron output.
    float derivative;
    //! Current neuron error.
    float sigma;
    //! Current neuron error delta.
    float delta;

    float valuePending;
    float derivePending;

    vector<Link*> linksFrom;
    vector<Link*> linksTo;
    Neuron();
    Neuron(bool isInput, bool isOutput);
};

#endif // LAYER_H
