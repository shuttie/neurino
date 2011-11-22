#ifndef BENCHRPROPXOR_H
#define BENCHRPROPXOR_H

#include "bench.h"

class BenchRPropXor : public Bench {
public:
    BenchRPropXor(float targetError, int targetIteration);
    virtual void run();
};

#endif
