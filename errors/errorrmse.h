#ifndef ERRORRMSE_H
#define ERRORRMSE_H

#include "error.h"
#include "errormse.h"

class ErrorRMSE : public ErrorMSE {
public:
    ErrorRMSE();
    virtual float calculate(Network *net, NetworkData *dataset);
};

#endif
