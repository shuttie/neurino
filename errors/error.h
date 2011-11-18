#ifndef ERROR_H
#define ERROR_H

#include "data/networkdata.h"
#include "core/network.h"

class Error {
public:
    Error();
    virtual float calculate(Network* net, NetworkData* dataset) = 0;
};

#endif
