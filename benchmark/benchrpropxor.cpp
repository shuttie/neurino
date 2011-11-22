#include "benchrpropxor.h"

BenchRPropXor::BenchRPropXor(float targetError, int targetIteration)
    :Bench(targetError, targetIteration) {
}

void BenchRPropXor::run()
{
    NetworkData* data = generate_xor_data();
    Network* net = generate_xor_network();

    RPropAlgo algo;

    calculateFactors(net, data, &algo);

    delete data;
    delete net;
}
