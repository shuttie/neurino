#ifndef ERRORRMSE_H
#define ERRORRMSE_H

#include "networkerror.h"
#include "networkerrormse.h"

//! Root mean-square error.
/*!
  Calculates root mean-square error though the whole dataset.
  */

class NetworkErrorRMSE : public NetworkErrorMSE {
public:
    NetworkErrorRMSE();
    virtual float calculate(Network *net, NetworkData *dataset);
};

#endif
