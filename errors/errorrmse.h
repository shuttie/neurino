#ifndef ERRORRMSE_H
#define ERRORRMSE_H

#include "error.h"
#include "errormse.h"

//! Root mean-square error.
/*!
  Calculates root mean-square error though the whole dataset.
  */

class ErrorRMSE : public ErrorMSE {
public:
    ErrorRMSE();
    virtual float calculate(Network *net, NetworkData *dataset);
};

#endif
