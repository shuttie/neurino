#ifndef NETWORKDATA_H
#define NETWORKDATA_H

#include <vector>
#include <stdio.h>
#include "sample.h"

//! Basic NetworkData class.
/*!
  It's used to store pairs of input/output values for the network.
  There's a lot of custom loaders derived from this class:
  NetworkDataCsv for loading CSV files;
  NetworkDataArray for loading std::vector arrays;
  NetworkDataFann for loading FANN data files;
  NetworkDataProben for loading PROBEN data files;
  */
class NetworkData
{
public:
    unsigned int inputs;
    unsigned int outputs;
    //! This vector stores actual data samples.
    std::vector<Sample> samples;
    NetworkData(unsigned int inputs, unsigned int outputs);
};

#endif // NETWORKDATA_H
