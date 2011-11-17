#ifndef SAMPLE_H
#define SAMPLE_H

#include <vector>

//! A class used to store network input and output values.
/*!
  All Samples loaded into NetworkData class should have the same dimension, eg.
  the same number of inputs and uutputs.
  */

class Sample
{
public:
    std::vector<float> inputs;
    std::vector<float> outputs;
    //! Default constructor.
    /*!
      Keep in mind that you cannot use an empty sample - network itself does not have any
      data sanity checks due to performance reasons, you must sanitize the data by yourself.
      */
    Sample();
    //! Constructor with default values.
    /*!
      'inputs.size()' should be equal to 'inputs', 'outputs.size()' should be equal to outputs.
      \param inputs an array of input float values.
      \param outputs an array of output float values.
      */
    Sample(std::vector<float> inputs, std::vector<float> outputs);
};

#endif // SAMPLE_H
