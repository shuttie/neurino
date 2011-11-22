#include "bench.h"
#include "benchbpropbatchxor.h"
#include "benchbpropxor.h"
#include "benchrpropxor.h"

int main(int argc, char** argv) {
    setbuf(stdout, NULL);

    BenchBPropXor       test1(0.1, 10000);
    BenchBPropBatchXor  test2(0.1, 10000);
    BenchRPropXor       test3(0.1, 10000);

    test1.bench(100);
    test2.bench(100);
    test3.bench(100);

    test1.print();
    test2.print();
    test3.print();
}
