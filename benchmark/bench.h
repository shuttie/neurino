#ifndef BENCH_H
#define BENCH_H

#include <vector>
#include <limits.h>
#include <sys/time.h>
#include "neurino.h"
#include "common.h"

using namespace std;

class Bench {
public:
    float targetError;
    int targetIteration;

    vector<bool> convergences; // got targetError on targetIteration
    vector<float> errors; // error values on targetIteration
    vector<int> iterations; // iterations on targetError
    vector<int> msecs;

    Bench(float targetError, int targetIteration);
    virtual void run() = 0;
    void bench(int tests = 100);
    void print();
protected:
    void calculateFactors(Network* net, NetworkData* data, Algo* algo);
private:
    long tvdiff(timeval start, timeval finish);
};

#endif
