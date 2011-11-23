#ifndef ERRORMSE_H
#define ERRORMSE_H

#include "error.h"

//! Mean-square error.
/*!
  Calculates mean-square error though the whole dataset.
  */

class ErrorMSE : public Error {
public:
    ErrorMSE();
    virtual float calculate(Network *net, NetworkData *dataset);
};

#endif
