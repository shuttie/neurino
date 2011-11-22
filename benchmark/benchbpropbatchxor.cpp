#include "benchbpropbatchxor.h"

BenchBPropBatchXor::BenchBPropBatchXor(float targetError, int targetIteration)
    :Bench(targetError, targetIteration) {
}

void BenchBPropBatchXor::run()
{
    NetworkData* data = generate_xor_data();
    Network* net = generate_xor_network();

    BPropBatchAlgo algo;

    calculateFactors(net, data, &algo);

    delete data;
    delete net;
}
