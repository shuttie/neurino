#ifndef NEURON_H
#define NEURON_H

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
    float valuePending;
    float derivePending;
    float bpSigma;
    float rpDelta;
    Neuron();
    Neuron(bool isInput, bool isOutput);
};

#endif // LAYER_H
