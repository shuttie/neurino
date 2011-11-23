#ifndef LAYER_H
#define LAYER_H

#include "function.h"
#include "neuron.h"
#include "link.h"
#include <vector>

using namespace std;

//! Basic network layer.
/*!
  Contains a bunch of neurons and their links.
  Neuron links are stored in google::dense_hash_map for performance reasons.

  If you're writing an application which does not extend the library, you souldn't
  directly call any methods from this class.
  */
class Layer {
public:
    bool isInput;
    bool isOutput;
    unsigned int neuronCount;
    //! Layer's activation function.
    Function* activationFunction;
    //! All layer's neurons.
    vector<Neuron> neurons;
    //! Bias neuron.
    Neuron biasNeuron;

    //! Constructor
    /*!
      \param neuronCount layer neuron count. Also there is a hidden bias neuron.
      \param activationFunction layer activation function. In theory different network layers
      can have different activation functions.
      */
    Layer(unsigned int neuronCount, Function* activationFunction);
    ~Layer();
    //! Update layer inputs with custom values.
    void setInputs(vector<float> &inputs);
    //! Front-propagate neurons in layer.
    void propagate();
};

#endif // LAYER_H
