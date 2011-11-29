#ifndef ERRORMSE_H
#define ERRORMSE_H

#include "networkerror.h"

//! Mean-square error.
/*!
  Calculates mean-square error though the whole dataset.
  */

class NetworkErrorMSE : public NetworkError {
public:
    NetworkErrorMSE();
    virtual float calculate(Network *net, NetworkData *dataset);
};

#endif
