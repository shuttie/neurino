#ifndef BENCHBPROPBATCHXOR_H
#define BENCHBPROPBATCHXOR_H

#include "bench.h"

class BenchBPropBatchXor : public Bench {
public:
    BenchBPropBatchXor(float targetError, int targetIteration);
    virtual void run();
};

#endif
