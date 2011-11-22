#include "benchbpropxor.h"

BenchBPropXor::BenchBPropXor(float targetError, int targetIteration)
    :Bench(targetError, targetIteration) {
}

void BenchBPropXor::run()
{
    NetworkData* data = generate_xor_data();
    Network* net = generate_xor_network();

    BPropAlgo algo;

    calculateFactors(net, data, &algo);

    delete data;
    delete net;
}
