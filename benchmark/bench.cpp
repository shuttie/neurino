#include "bench.h"

Bench::Bench(float targetError, int targetIteration)
    :targetError(targetError), targetIteration(targetIteration) {

}

void Bench::print()
{
    // Convergence percent
    float convergencePercent = 0.0f;
    for (int i=0; i<convergences.size(); ++i)
        if (convergences[i])
            convergencePercent += 1.0f;
    convergencePercent /= (float)convergences.size();

    // Average iteration to got targetError
    float avgIteration = 0;
    for (int i=0; i<iterations.size(); ++i)
        avgIteration += iterations[i];
    avgIteration /= (float)iterations.size();

    // Average error on targetIteration
    float avgError = 0;
    for (int i=0; i<errors.size(); ++i)
        avgError += errors[i];
    avgError /= (float)errors.size();

    // Average iteration time
    float avgTime = 0;
    for (int i=0; i<msecs.size(); ++i)
        avgTime += msecs[i];
    avgTime /= (float)msecs.size();

    printf("tests: %4d converged: %4.2f avgIt: %6.1f avgErr: %8f time: %8f\n", 0, convergencePercent, avgIteration, avgError, avgTime);
}

void Bench::bench(int tests)
{
    printf("running: ");
    for (int i=0; i<tests; ++i) {
        run();
        printf("\rrunning: %d/%d",i,tests-1);
    }
    printf("\n");
}

void Bench::calculateFactors(Network* net, NetworkData* data, Algo* algo)
{
    NetworkErrorMSE error;

    float err = 1000000;
    bool converged = false;
    timeval start, finish;
    gettimeofday(&start, NULL);
    for (int i=0; i< targetIteration; ++i) {
        algo->learn(net, data);
        err = error.calculate(net, data);
        if ((err < targetError) && !converged) {
            converged = true;
            iterations.push_back(i);
        }
    }
    gettimeofday(&finish, NULL);
    msecs.push_back(tvdiff(start,finish));
    errors.push_back(err);
    convergences.push_back(converged);
}

long Bench::tvdiff(timeval start, timeval finish)
{
    long msec;
    msec=(finish.tv_sec-start.tv_sec)*1000;
    msec+=(finish.tv_usec-start.tv_usec)/1000;
    return msec;
}
