#ifndef BENCHBPROPXOR_H
#define BENCHBPROPXOR_H

#include "bench.h"

class BenchBPropXor : public Bench {
public:
    BenchBPropXor(float targetError, int targetIteration);
    virtual void run();
};

#endif
