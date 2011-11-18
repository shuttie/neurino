#ifndef ERRORMSE_H
#define ERRORMSE_H

#include "error.h"

class ErrorMSE : public Error {
public:
    ErrorMSE();
    virtual float calculate(Network *net, NetworkData *dataset);
};

#endif
