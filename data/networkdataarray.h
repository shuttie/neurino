#ifndef NETWORKDATAARRAY_H
#define NETWORKDATAARRAY_H

#include <vector>
#include "networkdata.h"

//! A class for creating NetworkData dataset from STL arrays.
/*!
  It perdorms some sanity checks and discards broken data.
  */
class NetworkDataArray : public NetworkData
{
public:
    NetworkDataArray(unsigned int inputs, unsigned int outputs, std::vector<std::vector<float> > inputData, std::vector<std::vector<float> > outputData);
};

#endif // NETWORKDATAARRAY_H
