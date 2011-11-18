#ifndef ALGO_H
#define ALGO_H

#include "data/networkdata.h"
#include "core/network.h"

class Algo {
public:
    Algo();
    virtual void learn(Network* net, NetworkData* data) = 0;
};

#endif //ALGO_H
